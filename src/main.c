#include "headers.h"

int *pid_array = NULL;
int fore_count = 0;
// int cmp=0;
int std_out = (STDOUT_FILENO), std_in = (STDIN_FILENO);
struct process_running *running = NULL;
int pid_neel = 0;
// struct process_running
// {
//     pid_t pid;
//     bool status;
// };
int fore = 0;
// int fore_pid=0;
int flag_njui = 0;

void handle_sigint(int signum)
{
}

void handle_sigtstp(int sig)
{
    // printf("Received SIGTSTP (%d). Exiting...\n", sig);

    // printf("\n");
}

void bring_to_foreground(pid_t pid)
{

    int status;
    waitpid(pid, &status, WUNTRACED);

    // Set the foreground process group back to the shell's PID
    // tcsetpgrp(STDIN_FILENO, getpgrp());
}

void store(char *input, char *last, int line_count, char *current_line, char *output_path, char *home, char **line_array)
{
    if (last[strlen(last) - 1] == '\n')
        last[strlen(last) - 1] = '\0';
    // printf("%s\n",last);
    if (strcmp(input, last) == 0)
        return;
    else
    {

        if (line_count >= 15)
        {
            FILE *temp_file = fopen(output_path, "w");
            fclose(temp_file);
            FILE *file = fopen(output_path, "a");
            // printf("Hi\n");
            fseek(file, 0, SEEK_SET);
            for (int i = 1; i < 15; i++)
                fprintf(file, "%s", line_array[i]);
            // fprintf(file, "%s\n",input);
            fclose(file);
            // fclose(temp_file);
            // remove(output_path);
            // rename(tmp, output_path);
            file = fopen(output_path, "a");
            fprintf(file, "%s\n", input);
            fclose(file);
        }
        else
        {
            FILE *file = fopen(output_path, "a");
            fprintf(file, "%s\n", input);
            fclose(file);
        }
    }
}

void sigttou_handler(int signo)
{
    // Do nothing, just ignore the signal
}

int main()
{
    pid_array = (int *)malloc(sizeof(int) * qt);
    signal(SIGINT, handle_sigint);

    struct sigaction sa1;
    sa1.sa_handler = handle_sigtstp;
    sa1.sa_flags = SA_RESTART;
    sigaction(SIGTSTP, &sa1, NULL);

    char memory[qt];
    int count_running = 0;
    running = (struct process_running *)malloc(sizeof(struct process_running) * qt);
    for (int i = 0; i < qt; i++)
        running[i].status = false;
    int cmp = 0;
    char *path_output = (char *)malloc(sizeof(char) * qt);
    char *home = (char *)malloc(sizeof(char) * qt);
    int home_len = 0;
    getcwd(home, qt);
    home_len = strlen(home);
    // printf("%s\n",home);
    // strcpy(path_output,home);
    for (int i = 0; i < home_len; i++)
        path_output[i] = home[i];
    // printf("%s\n",home);
    strcat(path_output, "/pastevents.txt");
    // printf("%s\n",home);
    // getcwd(home,qt);
    // printf("%s\n",path_output);
    char *term = (char *)malloc(sizeof(char) * qt);
    char *home1 = (char *)malloc(sizeof(char) * qt);
    for (int i = 0; i < home_len; i++)
    {
        home1[i] = home[i];
    }
    for (int i = 0; i < qt; i++)
    {
        if (i == 0)
            term[i] = '~';
        else
            term[i] = '\0';
    }
    // printf("~");

    char *last = (char *)malloc(sizeof(char) * qt);
    char *last_term = (char *)malloc(sizeof(char) * qt);
    // last[0]='~';
    for (int i = 0; i < home_len; i++)
        last[i] = home[i];
    last_term[0] = '~';

    int output_fd_orig = dup(STDOUT_FILENO);
    int input_fd_orig = dup(STDIN_FILENO);
    pid_neel = output_fd_orig;
    while (1)
    {

        // Print appropriate prompt with username, systemname and directory before accepting input

        dup2(output_fd_orig, STDOUT_FILENO);
        // printf("cmp = %d\n",cmp);
        prompt();
        printf("%s>", term);
        if (cmp == 1)
        {
            cmp = 0;
            char *pwd = (char *)malloc(sizeof(char) * qt);
            getcwd(pwd, qt);
            // printf("%s\n",pwd);
            // printf("%ld %d\n",strlen(pwd),home_len);
            if (strlen(pwd) >= home_len)
            {
                char *new = (char *)malloc(sizeof(char) * qt);
                for (int i = home_len; i < strlen(pwd); i++)
                {
                    new[i - home_len] = pwd[i];
                }
                char *hom = (char *)malloc(sizeof(char) * qt);
                for (int i = 0; i < home_len; i++)
                {
                    hom[i] = home[i];
                }
                int l = strlen(term);
                for (int i = l - 1; i > 0; i--)
                {
                    term[i] = '\0';
                }
                // printf("jved\n");
                term[0] = '~';
                strcat(term, new);
                // term=hom;
                // for(int )
            }

            else
            {
                int l = strlen(term);
                for (int i = 0; i < l; i++)
                    term[i] = '\0';
                for (int i = 0; i < strlen(pwd); i++)
                {
                    term[i] = pwd[i];
                }
            }
        }
        char input_init[4096];
        // fgets(input_init,4096,stdin);
        // printf("dndnekd\n");
        dup2(input_fd_orig, STDIN_FILENO);
        if (fgets(input_init, 4096, stdin) == NULL)
        {
            printf("\n");
            exit(0);
        }
        int len = strlen(input_init);
        if (len > 0 && input_init[len - 1] == '\n')
        {
            input_init[len - 1] = '\0';
        }
        // printf("%d\n",fore_count);
        for (int m = 0; m < fore_count; m++)
        {
            if (pid_array[m] > 0)
            {
                char path_of_a_process_file[256];
                char info[128];
                snprintf(path_of_a_process_file, sizeof(path_of_a_process_file), "/proc/%d/status", pid_array[m]);
                FILE *fptr1 = fopen(path_of_a_process_file, "r");
                if (fptr1 != NULL)
                {
                    while (fgets(info, sizeof(info), fptr1))
                    {
                        if (strncmp(info, "State:", 6) == 0)
                        {
                            if (strstr(info, "Z"))
                            {
                                printf("Process with PID %d is completed.\n", pid_array[m]);
                                pid_array[m] = 0;
                            }
                            break;
                        }
                    }
                    fclose(fptr1);
                }
            }
        }

        // printf("%s\n",path_output);
        FILE *file = fopen(path_output, "r");
        // printf("%s\n",home);
        if (file == NULL)
        {
            perror("Error opening file");
            return 1;
        }

        char current_line[qt];
        char last_line[qt] = "";
        int line_count = 0;
        // Read each line and update last_line
        char **line_array = (char **)malloc(sizeof(char *) * 15);

        for (int i = 0; i < 15; i++)
            line_array[i] = (char *)malloc(sizeof(char) * qt);

        while (fgets(current_line, qt, file) != NULL)
        {
            strcpy(last_line, current_line);

            strcpy(line_array[line_count], current_line);
            line_count++;
            // free(current_line);
        }
        // printf("halle dill\n");

        fclose(file);

        const char *delimiter = ";";
        char orig_input[qt];
        // printf("bffee\n");
        strcpy(orig_input, input_init);

        if (strstr(orig_input, "pastevents") == NULL)
        {
            store(orig_input, last_line, line_count, current_line, path_output, home, line_array);
        }
        else
        {
            if (strstr(orig_input, "pastevents execute") != NULL)
            {

                // store(orig_input,last_line,line_count,current_line,path_output,home,line_array);
            }
        }

        char *var = strtok(input_init, delimiter);
        char **input = (char **)malloc(sizeof(char *) * qt);
        for (int i = 0; i < qt; i++)
            input[i] = (char *)malloc(sizeof(char) * qt);
        int num_of_args = 0;
        while (var != NULL)
        {
            strcpy(input[num_of_args++], var);
            var = strtok(NULL, delimiter);
        }
        // strcpy(in)
        // printf("jbdw%s\n",input_init);
        char orig_inp1[qt];
        strcpy(orig_inp1, orig_input);
        for (int i = num_of_args; i < qt; i++)
            input[i] = NULL;
        for (int o = 0; o < num_of_args; o++)
        {
            strcpy(orig_input, orig_inp1);
            // printf("%s\n",orig_input);
            // printf("%s\n",input[o]);
            // printf("djbe %s\n",orig_input);
            int found = 0;
            for (int i = 0; orig_input[i] != '\0'; i++)
            {
                if (orig_input[i] == '|')
                {
                    found = 1;
                    break;
                }
            }

            int found1 = 0;

            for (int i = 0; orig_input[i] != '\0'; i++)
            {
                if (orig_input[i] == '>' || orig_input[i] == '<')
                {
                    found1 = 1;
                    break;
                }
            }

            if (found && found1 == 0)
            {
                piping(orig_input, last_line, line_count, current_line, path_output, home, line_array, term, home_len, last, last_term, memory, fore_count, count_running, pid_array, 0, &cmp);
                // printf("udbe\n");
                continue;
            }
            else if (found1 && found == 0)
            {

                redirect(orig_input, last_line, line_count, current_line, path_output, home, line_array, term, home_len, last, last_term, memory, fore_count, count_running, pid_array, 0, &cmp);
                continue;
            }
            else if (found1 && found)
            {
                // pipdirect();
                // printf("wjdbw\n");
                pipdirect(orig_input, last_line, line_count, current_line, path_output, home, line_array, term, home_len, last, last_term, memory, fore_count, count_running, pid_array, 0, &cmp);
                continue;
            }

            const char *delim1 = "&";
            char *u1 = (char *)malloc(sizeof(char) * qt);
            strcpy(u1, input[o]);
            // printf("%s\n",u);
            char *str1 = strtok(input[o], delim1);
            // str[strlen(str)]='\0';
            char **entries1 = (char **)malloc(sizeof(char *) * qt);
            for (int i = 0; i < qt; i++)
            {
                entries1[i] = (char *)malloc(sizeof(char) * qt);
            }

            int str_index = 0;
            int index1 = 0;
            int count_amper = 0;
            for (int i = strlen(u1) - 1; i >= 0; i--)
            {
                if (u1[i] == ' ' || u1[i] == '\t')
                {
                    // Replace spaces and tabs with null characters
                    u1[i] = '\0';
                }
                else
                {
                    // Stop when a non-space and non-tab character is encountered
                    break;
                }
            }
            while (u1[str_index] != '\0')
            {
                if (u1[str_index++] == '&')
                    count_amper++;
            }

            // printf("%d\n",count_amper);
            while (str1 != NULL)
            {
                // printf("%s\n",str);
                entries1[index1++] = str1;
                str1 = strtok(NULL, delim1);
                // str[strlen(str)]='\0';
            }
            int l;
            // printf("index: %d\n",index1);
            for (l = 0; l < (index1 - 1); l++)
            {
                execute_command(entries1[l], last_line, line_count, current_line, path_output, home, line_array, term, home_len, last, last_term, memory, &fore_count, count_running, pid_array, 1, &cmp);
            }
            if (index1 > 1)
            {
                if (u1[strlen(u1) - 1] == '&')
                    execute_command(entries1[l], last_line, line_count, current_line, path_output, home, line_array, term, home_len, last, last_term, memory, &fore_count, count_running, pid_array, 1, &cmp);
                else
                    execute_command(entries1[l], last_line, line_count, current_line, path_output, home, line_array, term, home_len, last, last_term, memory, &fore_count, count_running, pid_array, 0, &cmp);
            }
            else
            {
                if (count_amper == 1)
                {
                    // printf("radn\n");
                    execute_command(entries1[l], last_line, line_count, current_line, path_output, home, line_array, term, home_len, last, last_term, memory, &fore_count, count_running, pid_array, 1, &cmp);
                }
                else
                    execute_command(entries1[l], last_line, line_count, current_line, path_output, home, line_array, term, home_len, last, last_term, memory, &fore_count, count_running, pid_array, 0, &cmp);
            }
            // printf("kacho\n");
            // exit(0);
            continue;

            // entries1[num_of_args]=NULL;
            // printf("Input entered :%s\n",input);
            const char *delim = " \t";
            char *u = (char *)malloc(sizeof(char) * qt);
            strcpy(u, input[o]);
            // printf("%s\n",u);
            char *str = strtok(input[o], delim);
            // str[strlen(str)]='\0';
            char **entries = (char **)malloc(sizeof(char *) * qt);
            for (int i = 0; i < qt; i++)
            {
                entries[i] = (char *)malloc(sizeof(char) * qt);
            }

            int index = 0;
            while (str != NULL)
            {
                // printf("%s\n",str);
                entries[index++] = str;
                str = strtok(NULL, delim);
                // str[strlen(str)]='\0';
            }
            // strcpy(input,u);
            // printf("%s\n",input);
            // printf("%s\n",entries[0]);
            // entries[index]=NULL;
            for (int i = index; i < qt; i++)
                entries[i] = NULL;
            if (strcmp(entries[0], "warp") == 0)
            {
                // printf("%s\n",home);
                store(u, last_line, line_count, current_line, path_output, home, line_array);
                // printf("%d\n",index);
                for (int k = 0; k < (index - 1); k++)
                    warp(entries, home, term, home_len, last, last_term, index, memory, k + 1);
            }
            else if (strcmp(entries[0], "peek") == 0)
            {
                store(u, last_line, line_count, current_line, path_output, home, line_array);
                // printf("%d\n",index
                peek(entries, home, term, home_len, last, last_term, index);
            }
            else if (strcmp(entries[0], "pastevents") == 0)
            {
                // printf("Hi\n");
                pastevents(entries, input[o], last, line_count, current_line, path_output, home, line_array, index, term, last_term, home_len, index, memory, path_output, count_running, &cmp);
            }
            else if (strcmp(entries[0], "proclore") == 0)
            {
                // printf("hi %d\n",index);
                proclore(entries, index, home_len, home);
            }
            else if (strcmp(entries[0], "seek") == 0)
            {
                seek(entries, index, home, term);
            }
            else if (strcmp(entries[0], "activities") == 0)
            {
                activities();
            }
            else if (strcmp(entries[0], "ping") == 0)
            {
                ping(entries);
            }
            else if (strcmp(entries[0], "exit") == 0)
                exit(0);
            else if (strcmp(entries[0], "fg") == 0)
            {
                // printf("%d\n",getpid());
                for (int i = 0; i < fore_count; i++)
                {
                    // printf("%d\n",fore_pid[i]);
                    if (status_proc(pid_array[i]) == 'S' || status_proc(pid_array[i]) == 'R')
                    {
                        kill(pid_array[i], SIGCONT);
                        signal(SIGINT, handle_sigint);
                        struct sigaction sa1;
                        sa1.sa_handler = &handle_sigtstp;
                        sa1.sa_flags = SA_RESTART;
                        sigaction(SIGTSTP, &sa1, NULL);
                        int status;
                        waitpid(pid_array[i], &status, WUNTRACED);
                    }
                }
            }

            else if (strcmp(entries[0], "bg") == 0)
            {
                pid_t p = atoi(entries[1]);

                // Check if the process with the given PID exists
                if (kill(p, 0) == -1)
                {
                    perror("kill");
                    fprintf(stderr, "No such process found with PID %d\n", p);
                    // return 1;
                }

                if (kill(p, SIGCONT) == -1)
                {
                    perror("kill");
                    fprintf(stderr, "Failed to resume process with PID %d\n", p);
                    // return 1;
                }
                signal(SIGINT, handle_sigint);
                struct sigaction sa1;
                sa1.sa_handler = &handle_sigtstp;
                sa1.sa_flags = SA_RESTART;
                sigaction(SIGTSTP, &sa1, NULL);
            }
            else if (strcmp(entries[0], "neonate") == 0)
            {
                neonate(entries);
            }
            else if (strcmp(entries[0], "iMan") == 0)
            {
                iman(entries);
            }
            else
            {
                // printf("Hi\n");
                store(u, last_line, line_count, current_line, path_output, home, line_array);
                double val;
                syst(entries, home, index, term, count_running, u, pid_array, &fore_count, 0, &cmp, &val);
                // if(())
                if (val != INF && val != -1)
                {
                    if (val > 2)
                    {
                        int num;
                        if (val / (((double)((int)val) + 0.5)) > 1)
                            num = (int)val + 1;
                        else
                            num = (int)val;
                        char *string = (char *)malloc(sizeof(char) * 3);
                        if (num > 9)
                        {
                            char ch1 = (char)(num % 10 + 48);
                            char ch2 = (char)(num / 10 + 48);
                            string[0] = ch1;
                            string[1] = ch2;
                            string[2] = '\0';
                        }
                        else
                        {
                            string[0] = (char)(num + 48);
                            string[1] = '\0';
                        }

                        char buf[qt];
                        strcpy(buf, term);
                        snprintf(term, qt, "%s %s : %ss", buf, entries[0], string);
                        cmp = 1;
                    }
                }
                else if (val == INF)
                {
                    // printf("%f\n",val);
                    count_running++;
                    printf("%d\n", running[count_running - 1].pid);
                }
            }
        }
    }
}
