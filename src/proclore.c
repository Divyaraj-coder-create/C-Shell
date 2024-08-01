#include "headers.h"

void proclore(char **entries, int num_entries, int home_len, char *home)
{

    char *proc = "/proc";
    pid_t current = getpid();
    char **vals = (char **)malloc(sizeof(char *) * 5);
    for (int i = 0; i < 5; i++)
        vals[i] = (char *)malloc(sizeof(char) * 4096);
    char line[4096];
    if (num_entries == 1)
    {
        // printf("hello\n");
        char *path = (char *)malloc(sizeof(char) * 4096);
        snprintf(path, qt, "%s/%d/status", proc, current);
        // printf("%s\n",path);
        FILE *fl = fopen(path, "r");
        snprintf(vals[0], qt, "%d", current);
        while (fgets(line, qt, fl) != NULL)
        {
            if (line[strlen(line) - 1] == '\n')
                line[strlen(line) - 1] = '\0';
            int l = strlen(line);
            // printf("%s\n",line);
            char **inp = (char **)malloc(sizeof(char *) * qt);
            for (int i = 0; i < qt; i++)
                inp[i] = (char *)malloc(sizeof(char) * qt);
            char *delim = " |\t|:";
            char *yy = strtok(line, delim);
            int var = 0;
            //    sprintf()
            while (yy != NULL)
            {
                // inp[var++]=yy;
                strcpy(inp[var++], yy);
                yy = strtok(NULL, delim);
            }

            // strtok()
            // while(inp)
            // printf("%s", line); // Print each line
            char one[5];
            if (strcmp(inp[0], "State") == 0)
            {
                strcpy(vals[1], inp[1]);
            }
            char ans[100];
            snprintf(ans, sizeof(ans), "%d", getpgid(current));
            strcpy(vals[2], ans);
            if (strcmp(inp[0], "VmSize") == 0)
                strcpy(vals[3], inp[1]);
        }
        pid_t foreground_pgid = tcgetpgrp(STDIN_FILENO);
        int target_pid = current;
        // Get the process group ID of the target process
        pid_t target_pgid = getpgid(target_pid);

        // for(int i=0;i<4;i++)
        {
            printf("pid : %s\n", vals[0]);
            if (target_pgid == foreground_pgid || strcmp(vals[1], "Z") == 0)
                printf("process status : %s\n", vals[1]);
            else
                printf("process status : %s+\n", vals[1]);
            printf("Process group : %s\n", vals[2]);
            printf("Virtual Memory : %s\n", vals[3]);
        }

        // printf("%s\n",vals[i]);
        fclose(fl);

        //  char *path=(char *)malloc(sizeof(char)*4096);
        // snprintf(path,qt,"%s/%d/status",proc,current);
        char exe_path[1024];
        memset(exe_path, 0, sizeof(exe_path));
        sprintf(exe_path, "/proc/%d/exe", current);
        ssize_t len = readlink(exe_path, exe_path, sizeof(exe_path) - 1);
        if (len != -1)
        {
            // printf("Executable Path: %s\n", exe_path);
            // vals[4]
        }
        else
        {
            perror("readlink");
        }

        if (strlen(exe_path) >= home_len)
        {
            char *new = (char *)malloc(sizeof(char) * qt);
            for (int i = home_len; i < strlen(exe_path); i++)
            {
                new[i - home_len] = exe_path[i];
            }
            char *hom = (char *)malloc(sizeof(char) * qt);
            for (int i = 0; i < home_len; i++)
            {
                hom[i] = exe_path[i];
            }
            int l = strlen(exe_path);
            for (int i = l - 1; i > 0; i--)
            {
                exe_path[i] = '\0';
            }
            // printf("jved\n");
            exe_path[0] = '~';
            strcat(exe_path, new);
            // term=hom;
            // for(int )
            strcpy(vals[4], exe_path);
        }

        printf("executable path : %s\n", vals[4]);
    }
    else
    {

        // printf("hello\n");
        char *path = (char *)malloc(sizeof(char) * 4096);
        snprintf(path, qt, "%s/%s/status", proc, entries[1]);
        // printf("%s\n",path);
        FILE *fl = fopen(path, "r");
        snprintf(vals[0], qt, "%s", entries[1]);
        while (fgets(line, qt, fl) != NULL)
        {
            if (line[strlen(line) - 1] == '\n')
                line[strlen(line) - 1] = '\0';
            int l = strlen(line);
            // printf("%s\n",line);
            char **inp = (char **)malloc(sizeof(char *) * qt);
            for (int i = 0; i < qt; i++)
                inp[i] = (char *)malloc(sizeof(char) * qt);
            char *delim = " |\t|:";
            char *yy = strtok(line, delim);
            int var = 0;
            //    sprintf()
            while (yy != NULL)
            {
                // inp[var++]=yy;
                strcpy(inp[var++], yy);
                yy = strtok(NULL, delim);
            }

            // strtok()
            // while(inp)
            // printf("%s", line); // Print each line
            char one[5];
            if (strcmp(inp[0], "State") == 0)
            {
                strcpy(vals[1], inp[1]);
            }
            char ans[100];
            snprintf(ans, sizeof(ans), "%d", getpgid(atoi(entries[1])));
            strcpy(vals[2], ans);
            if (strcmp(inp[0], "VmSize") == 0)
                strcpy(vals[3], inp[1]);
        }
        pid_t foreground_pgid = tcgetpgrp(STDIN_FILENO);
        int target_pid = atoi(entries[1]);
        // Get the process group ID of the target process
        pid_t target_pgid = getpgid(target_pid);

        // if (target_pgid == foreground_pgid) {
        //     printf("Process with PID %d is likely in the foreground.\n", target_pid);
        // } else {
        //     printf("Process with PID %d is likely in the background.\n", target_pid);
        // }

        // for(int i=0;i<4;i++)
        {
            printf("pid : %s\n", vals[0]);
            if (target_pgid == foreground_pgid)
                printf("process status : %s\n", vals[1]);
            else
                printf("process status : %s+\n", vals[1]);
            printf("Process group : %s\n", vals[2]);
            printf("Virtual Memory : %s\n", vals[3]);
        }

        // printf("%s\n",vals[i]);
        fclose(fl);

        //  char *path=(char *)malloc(sizeof(char)*4096);
        // snprintf(path,qt,"%s/%d/status",proc,current);
        char exe_path[1024];
        memset(exe_path, 0, sizeof(exe_path));
        sprintf(exe_path, "/proc/%d/exe", getpgid(atoi(entries[1])));
        ssize_t len = readlink(exe_path, exe_path, sizeof(exe_path) - 1);
        if (len != -1)
        {
            // printf("Executable Path: %s\n", exe_path);
            // vals[4]
        }
        else
        {
            perror("readlink");
        }

        if (strlen(exe_path) >= home_len)
        {
            char *new = (char *)malloc(sizeof(char) * qt);
            for (int i = home_len; i < strlen(exe_path); i++)
            {
                new[i - home_len] = exe_path[i];
            }
            char *hom = (char *)malloc(sizeof(char) * qt);
            for (int i = 0; i < home_len; i++)
            {
                hom[i] = exe_path[i];
            }
            int l = strlen(exe_path);
            for (int i = l - 1; i > 0; i--)
            {
                exe_path[i] = '\0';
            }
            // printf("jved\n");
            exe_path[0] = '~';
            strcat(exe_path, new);
            // term=hom;
            // for(int )
            strcpy(vals[4], exe_path);
        }
        else
            strcpy(vals[4], exe_path);

        // printf("%s\n",exe_path);

        printf("executable path : %s\n", vals[4]);
    }
    // snprintf()
}
