#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function
void sigint_handler(int signum) {
    printf("\nCTRL+C pressed. Interrupting process...\n");
    // Add code to handle SIGINT here, if needed
}

int main() {
    // Set up the signal handler for SIGINT
    signal(SIGINT, sigint_handler);

    while (1) {
        printf("Running foreground process...\n");
        sleep(1);
    }

    return 0;
}
