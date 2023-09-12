#include "headers.h"




void ping(char **entries)
{
    // printf("%s %s\n",entries[1],entries[2]);
    pid_t target_pid = atoi(entries[1]);
    int signal_num = atoi(entries[2]);
     // Ensure the signal number is within the range of valid signals (0-31)
    signal_num = signal_num % 32;

    // Check if the process with the given PID exists
    if (kill(target_pid, 0) == -1) {
        perror("No such process found");
        return;
    }    
    // Send the specified signal to the process
    if (kill(target_pid, signal_num) == -1) {
        perror("Error sending signal");
        return;
    }
    printf("Sent signal %d to process with pid %d\n", signal_num, target_pid);
}















