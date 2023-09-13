#include "headers.h"




int cmp=0;
void execute_command(char *command,char *last_line,int line_count,char* current_line,char* path_output,char *home,char** line_array,char* term,int home_len,char* last,char* last_term,char* memory,int fore_count,int count_running,int* fore_pid) {
    
    // printf("%s\n",command);
    // char *args[qt];
    // char *token;
    // int arg_count = 0;


    // printf("%s\n",command);




    // Tokenize the command string
    

    // entries1[num_of_args]=NULL;
        // printf("Input entered :%s\n",input);
        const char* delim=" \t";
        char *u=(char *)malloc(sizeof(char)*qt);
        strcpy(u,command);
        // printf("%s\n",u);
        char *str=strtok(command,delim);
        // str[strlen(str)]='\0';
        char **entries=(char **)malloc(sizeof(char*)*qt);
        for(int i=0;i<qt;i++)
        {
            entries[i]=(char *)malloc(sizeof(char)*qt);
        }
        
        int index=0;
        while(str!=NULL)
        {
            // printf("%s\n",str);
            entries[index++]=str;
            str=strtok(NULL,delim);
            // str[strlen(str)]='\0';
        }
        // strcpy(input,u);
        // printf("%s\n",input);
        // printf("%s\n",entries[0]);
        // entries[index]=NULL;
        for(int i=index;i<qt;i++)
        entries[i]=NULL;
        if(strcmp(entries[0],"warp")==0)
        {
            // printf("%s\n",home);
            store(u,last_line,line_count,current_line,path_output,home,line_array);
            // printf("%d\n",index);
            for(int k=0;k<(index-1);k++)
            warp(entries,home,term,home_len,last,last_term,index,memory,k+1);
        }
        else if(strcmp(entries[0],"peek")==0)
        {
            store(u,last_line,line_count,current_line,path_output,home,line_array);
            // printf("%d\n",index
            peek(entries,home,term,home_len,last,last_term,index);
        }
        else if(strcmp(entries[0],"pastevents")==0)
        {
            // printf("Hi\n");
            pastevents(entries,command,last,line_count,current_line,path_output,home,line_array,index,term,last_term,home_len,index,memory);
            
        }
        else if(strcmp(entries[0],"proclore")==0)
        {
            // printf("hi %d\n",index);
            proclore(entries,index,home_len,home);
        }
        else if(strcmp(entries[0],"seek")==0)
        {
            seek(entries,index,home,term);
        }
        else if(strcmp(entries[0],"activities")==0)
        {
            activities();
        }
        else if(strcmp(entries[0],"ping")==0)
        {
            ping(entries);
        }
        else if(strcmp(entries[0],"exit")==0)
        exit(0);
        else if(strcmp(entries[0],"fg")==0)
        {
            printf("%d\n",getpid());
            for(int i=0;i<fore_count;i++)
            {
                printf("%d\n",fore_pid[i]);
                if(status_proc(fore_pid[i])=='S' || status_proc(fore_pid[i])=='R')
                {
                    kill(fore_pid[i],SIGCONT);
                    signal(SIGINT, handle_sigint);
                    struct sigaction  sa1;
                    sa1.sa_handler= &handle_sigtstp;
                    sa1.sa_flags=SA_RESTART;
                    sigaction(SIGTSTP,&sa1,NULL);
                    int status;
                    waitpid(fore_pid[i],&status,WUNTRACED);
                }
            }
        }


        else if(strcmp(entries[0],"bg")==0)
        {
            pid_t p = atoi(entries[1]);

    // Check if the process with the given PID exists
    if (kill(p, 0) == -1) {
        perror("kill");
        fprintf(stderr, "No such process found with PID %d\n", p);
        // return 1;
    }

    if (kill(p, SIGCONT) == -1) {
        perror("kill");
        fprintf(stderr, "Failed to resume process with PID %d\n", p);
        // return 1;
    }


        }
        else if(strcmp(entries[0],"neonate")==0)
        {
            neonate(entries);
        }
        else if(strcmp(entries[0],"iMan")==0)
        {
            iman(entries);
        }
        else 
        {
            // printf("Ansh\n");
            store(u,last_line,line_count,current_line,path_output,home,line_array);
            double val=syst(entries,home,index,term,count_running,u,fore_pid,&fore_count);
            // if(())
            if(val!=INF&&val!=-1)
            {
                if(val>2)
            {
                int num;
            if(val/(((double)((int)val)+0.5))>1)
            num=(int)val+1;
            else
            num=(int)val;
                char *string=(char *)malloc(sizeof(char)*3);
                if(num>9)
                {
                    char ch1=(char)(num%10+48);
                    char ch2=(char)(num/10+48);
                    string[0]=ch1;
                    string[1]=ch2;
                    string[2]='\0';
                }
                else
                {
                    string[0]=(char)(num+48);
                    string[1]='\0';
                }
                
                char buf[qt];
                strcpy(buf,term);
                snprintf(term,qt,"%s %s : %ss",buf,entries[0],string);
                cmp=1;
            }
            }
            else if(val==INF)
            {
                // printf("%f\n",val);
                count_running++;
                printf("%d\n",running[count_running-1].pid);
            }            
        }


    // dup2(std_out,STDOUT_FILENO);
    // close(std_out);
    // Execute the command using execvp
    // execvp(args[0], args);
    // return;

    // If execvp fails, print an error message
    // perror("execvp");
    // exit(EXIT_FAILURE);wc

}


void piping(char *input,char *last_line,int line_count,char* current_line,char* path_output,char *home,char** line_array,char* term,int home_len,char* last,char* last_term,char* memory,int fore_count,int count_running,int* fore_pid)
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
            execute_command(commands[i],last_line,line_count,current_line,path_output,home,line_array,term,home_len,last,last_term,memory, fore_count,count_running,fore_pid); // Execute the command
            exit(0);
            // exit(EXIT_SUCCESS);
        } else {
            // Parent process
            close(pipes[1]); // Close write end of the pipe
            wait(NULL); // Wait for the child to finish
            close(input_fd); // Close the input of the previous command
            input_fd = pipes[0]; // Set the input for the next command to the read end of the pipe
        }
    }
    // dup2
    dup2(init_out,STDOUT_FILENO);
    dup2(init_inp, STDIN_FILENO);
    // printf("%d %d\n",STDIN_FILENO,STDOUT_FILENO);
    // close(init_inp);
    // close(init_out);
    // dup2()    
    // close(pipes[0]);
    // close(pipes[1]);
    // return 0;
}


