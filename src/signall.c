#include "headers.h"




void ping(char **entries)
{
    pid_t target_pid = atoi(entries[1]);
    int signal_num = atoi(entries[2]);
    signal_num = signal_num % 32;

    if (kill(target_pid, 0) == -1) {
        perror("No such process found");
        return;
    }    
    if (kill(target_pid, signal_num) == -1) {
        perror("Error sending signal");
        return;
    }
    printf("Sent signal %d to process with pid %d\n", signal_num, target_pid);
}















