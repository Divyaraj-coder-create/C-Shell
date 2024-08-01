#include "headers.h"
// #include "syst.h"

void syst(char **entries, char *home, int len, char *term, int num_running, char *input, int *fore_pi, int *fo, int back, int *cmp, double *syst_ret)
{

    // printf("swnwl%s %d\n",entries[0],back);
    // int init_stdout=dup(STDOUT_FILENO);
    int brkr = 0;
    char **perm = (char **)malloc(sizeof(char *) * (qt + 2));
    perm[0] = (char *)malloc(sizeof(char) * (qt));
    perm[1] = (char *)malloc(sizeof(char) * (qt));
    // printf("%d\n",len);

    pid_t child = fork();
    // printf("%d\n",*fore_count);
    pid_array[fore_count++] = child;

    struct timeval start_time, end_time;

    gettimeofday(&start_time, NULL);
    if (child > 0)
    {

        int status;
        // wait(NULL);
        if (back == 0)
        {
            // printf("%d\n",getpid());
            waitpid(child, &status, WUNTRACED);
            // printf("%d\n",getpid());
            fore = 0;
            // tcsetpgrp(STDIN_FILENO, getpgrp()); // Restore the terminal's foreground process group
            // child = 0;
            // printf("%d\n",status);
            gettimeofday(&end_time, NULL);
            double execution_time = (end_time.tv_sec - start_time.tv_sec) +
                                    (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
            // printf("Execution time: %f seconds\n", execution_time);
            if (execution_time > 2.0 && back == 0)
            {
                *syst_ret = execution_time;
                // return execution_time;
            }

            // return -1.0;
        }
        else
        {
            running[num_running].pid = child;
            running[num_running].status = true;
            // *num_running++;
            *syst_ret = INF;
            // return INF;
        }
        // exit(0);
    }
    else
    {
        
        if (back)
        {

            setpgid(getpid(), getpid());
            // dup2(init_stdout,STDOUT_FILENO);

            if (execvp(entries[0], entries) == -1)
                printf("ERROR: Invalid command\n");
        }
        else
        {
            // tcsetpgrp(STDIN_FILENO, getpid());
            // fore_pid=getpid();
            fore = 1;

            if (execvp(entries[0], entries) == -1)
                printf("ERROR: Invalid command\n");
        }
        // exit(0);
    }
    // execvp(directory,entries,);
}