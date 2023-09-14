#include "headers.h"

struct ProcessInfo
{
    char pid[16];
    char command[256];
    char state[16];
};

int compareProcessInfo(const void *a, const void *b)
{
    // Compare command names lexicographically
    return strcmp(((struct ProcessInfo *)a)->command, ((struct ProcessInfo *)b)->command);
}

char *get_process_state(char *pid)
{
    char proc_path[256];

    snprintf(proc_path, sizeof(proc_path), "/proc/%s/stat", pid);

    FILE *stat_file = fopen(proc_path, "r");
    if (stat_file == NULL)
    {
        return "stopped";
    }
    else
    {
        fclose(stat_file);
        return "running";
    }
}

char status_proc(pid_t p)
{
    if (kill(p, 0) == -1)
    {
        // perror("kill");
        // fprintf(stderr, "No such process found with PID %d\n", p);
        return 'Z';
    }
    char pid[100];
    snprintf(pid, 100, "%d", p);

    char state_path[256];
    snprintf(state_path, sizeof(state_path), "/proc/%s/status", pid);
    FILE *state_file = fopen(state_path, "r");

    if (state_file != NULL)
    {
        char state[256];
        while (fgets(state, sizeof(state), state_file))
        {
            if (strstr(state, "State:") != NULL)
            {
                char state_value[16];
                sscanf(state, "State:%s", state_value);
                // printf("%s\n",state_value);

                const char *state_string;
                if (state_value[0] == 'S' || state_value[0] == 'R')
                {
                    state_string = "Running";
                    return 'R';
                    // printf("%s : %s - %s\n", pid, command, state_string);
                }
                else if (state_value[0] == 'T')
                {
                    state_string = "Stopped";
                    // printf("%s : %s - %s\n", pid, command, state_string);
                    return 'S';
                }
                else
                {
                    return 'Z';
                }
            }
        }
    }
}

void activities()
{
    printf("PID | Command Name | State\n");

    DIR *proc_dir = opendir("/proc");
    if (proc_dir == NULL)
    {
        perror("opendir");
        exit(1);
    }

    pid_t shell_pid = getpid();

    struct dirent *entry;
    struct ProcessInfo processes[256];
    int processCount = 0;

    while ((entry = readdir(proc_dir)) != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            const char *pid = entry->d_name;
            if (atoi(pid) != 0)
            { // Check if it's a numeric directory (a process directory)
                char cmd_path[256];
                snprintf(cmd_path, sizeof(cmd_path), "/proc/%s/cmdline", pid);

                FILE *cmd_file = fopen(cmd_path, "r");
                if (cmd_file != NULL)
                {
                    if (fgets(processes[processCount].command, sizeof(processes[processCount].command), cmd_file))
                    {
                        // Remove trailing newline
                        processes[processCount].command[strcspn(processes[processCount].command, "\n")] = '\0';

                        // Check if the process was spawned by the custom shell
                        char parent_pid_path[256];
                        snprintf(parent_pid_path, sizeof(parent_pid_path), "/proc/%s/stat", pid);
                        FILE *parent_pid_file = fopen(parent_pid_path, "r");
                        if (parent_pid_file != NULL)
                        {
                            int parent_pid;
                            fscanf(parent_pid_file, "%*d %*s %*c %d", &parent_pid);
                            fclose(parent_pid_file);
                            if (parent_pid == shell_pid)
                            {
                                // Get the process state
                                char state_path[256];
                                snprintf(state_path, sizeof(state_path), "/proc/%s/status", pid);
                                FILE *state_file = fopen(state_path, "r");

                                if (state_file != NULL)
                                {
                                    char state[256];
                                    while (fgets(state, sizeof(state), state_file))
                                    {
                                        if (strstr(state, "State:") != NULL)
                                        {
                                            sscanf(state, "State:%s", processes[processCount].state);
                                            break;
                                        }
                                    }

                                    fclose(state_file);
                                }
                                else
                                {
                                    printf("Error open\n");
                                }

                                strcpy(processes[processCount].pid, pid);
                                processCount++;
                            }
                        }
                    }

                    fclose(cmd_file);
                }
            }
        }
    }

    closedir(proc_dir);

    // Sort the processes based on command names
    qsort(processes, processCount, sizeof(struct ProcessInfo), compareProcessInfo);

    // Print the sorted process information
    for (int i = 0; i < processCount; i++)
    {
        if (strstr(processes[i].state, "R") || strstr(processes[i].state, "S"))
            printf("%s : %s - Running\n", processes[i].pid, processes[i].command);
        else if (strstr(processes[i].state, "T"))
            printf("%s : %s - Stopped\n", processes[i].pid, processes[i].command);
    }
}