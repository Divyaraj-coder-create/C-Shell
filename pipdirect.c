#include "headers.h"





void pipdirect(char* input,char *last_line,int line_count,char* current_line,char* path_output,char *home,char** line_array,char* term,int home_len,char* last,char* last_term,char* memory,int fore_count,int count_running,int* fore_pid)
{
    char *commands[256]; 
    int command_count = 0;
    char *token = strtok(input, "|");
        while (token != NULL) 
        {
            commands[command_count] = token;
            command_count++;
            token = strtok(NULL, "|");
        }
        // printf("%d\n",command_count);
       int pipes[2];
    int input_fd = STDIN_FILENO;
    int init_inp=STDIN_FILENO;
    int init_out=STDOUT_FILENO;
    for (int i = 0; i < command_count; i++) {
        pipe(pipes); // Create a new pipe for each command
        // printf("%s\n",commands[i]);
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process
            close(pipes[0]); // Close read end of the pipe

            // Redirect input and output
            dup2(input_fd, STDIN_FILENO);
            if (i < command_count - 1) {
                dup2(pipes[1], STDOUT_FILENO); // Set stdout to the write end of the pipe (except for the last command)
            }

            close(pipes[1]); // Close write end of the pipe
            // printf("Divyaraj\n");
            redirect(commands[i],last_line,line_count,current_line,path_output,home,line_array,term,home_len,last,last_term,memory, fore_count,count_running,fore_pid); // Execute the command
            exit(0);
            // exit(EXIT_SUCCESS);
        } else {
            // Parent process
            close(pipes[1]);
            // printf("Ansh_SHAH\n"); // Close write end of the pipe
            wait(NULL);
            // printf("Ansh_shsh\n"); // Close write end of the pipe
             // Wait for the child to finish
            close(input_fd); // Close the input of the previous command
            input_fd = pipes[0]; // Set the input for the next command to the read end of the pipe
        }
    }
    // dup2
    // dup2(init_out,STDOUT_FILENO);
    // dup2(init_inp, STDIN_FILENO);
    // printf("%d %d\n",STDIN_FILENO,STDOUT_FILENO);


}