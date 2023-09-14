#include "headers.h"






void display(char **entries,char *input,char *last,int line_count,char* current_line,char *output_path,char *home,char **line_array,int num,int num_arg)
{
    if(num_arg==1)
    {FILE *file = fopen(output_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return ;
    }

    char line[qt]; // Buffer to hold each line

    // Read and print each line until the end of the file
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); // Print the line
    }

    // Close the file
    fclose(file);}
    
}


void execute(char * command,char *path_output,int count_running,char *home,char* term,int home_len,char* last,char* last_term,char* memory,int *cmp)
{
    
    
    
    // char *input3;
    //     int len5=strlen(command);
    //     input3=command;
    //     // printf("%d\n",len);
    //     if(len5>0&&input3[len5-1]=='\n')
    //     {
    //         input3[len5-1]='\0';
    //     }
    //     // printf("%s\n",path_output);
    //     FILE *file1 = fopen(path_output, "r");

    // if (file1 == NULL) 
    // {
    //     perror("Error opening file");
    //     return ;
    // }
    // char current_line1[MAX_LINE_LENGTH];
    // char last_line1[MAX_LINE_LENGTH] = "";
    // int line_count1 = 0;
    // // Read each line and update last_line
    // char** line_array1=(char **)malloc(sizeof(char *)*15);

    // for(int i=0;i<15;i++)
    // line_array1[i]=(char *)malloc(sizeof(char)*qt);

    // while (fgets(current_line1, sizeof(current_line1), file1) != NULL) {
    //     strcpy(last_line1, current_line1);
    //     strcpy(line_array1[line_count1],current_line1);
    //     line_count1++;
    // }

    // fclose(file1);
        


char input_init[qt];
strcpy(input_init,command);

            int len=strlen(input_init);
        if(len>0&&input_init[len-1]=='\n')
        {
            input_init[len-1]='\0';
        }
        for (int m = 0; m < count_running; m++)
        {
            if (running[m].pid > 0)
            {
                char path_of_a_process_file[256];
                char info[128];
                snprintf(path_of_a_process_file, sizeof(path_of_a_process_file), "/proc/%d/status", running[m].pid);
                FILE *fptr1 = fopen(path_of_a_process_file, "r");
                while (fgets(info, sizeof(info), fptr1))
                {
                    if (strncmp(info, "State:", 6) == 0)
                    {
                        if (strstr(info, "Z"))
                        {
                            printf("Process with PID %d is completed.\n", running[m].pid);
                            running[m].pid = 0;
                        }
                        break;
                    }
                }
                fclose(fptr1);
            }
        }

        // printf("%s\n",path_output);
        FILE *file = fopen(path_output, "r");
    // printf("%s\n",home);
    if (file == NULL) 
    {
        perror("Error opening file");
        return ;
    }

    char current_line[qt];
    char last_line[qt] = "";
    int line_count = 0;
    // Read each line and update last_line
    char** line_array=(char **)malloc(sizeof(char *)*15);

    for(int i=0;i<15;i++)
    line_array[i]=(char *)malloc(sizeof(char)*qt);

    while (fgets(current_line, qt , file) != NULL) {
        strcpy(last_line, current_line);
        // printf("%d\n",strlen(current_line));
        // for(int i=0;i<strlen(current_line);i++)
        // last_line[i]=current_line[i];
        // printf("%s",current_line);
        strcpy(line_array[line_count],current_line);
        line_count++;
        // free(current_line);
    }
        // printf("halle dill\n");


    fclose(file);

                
        const char* delimiter=";";
        char orig_input[qt];
        // printf("bffee\n");
        strcpy(orig_input,input_init);

        if(strstr(orig_input,"pastevents")==NULL)
        {
            store(orig_input,last_line,line_count,current_line,path_output,home,line_array);
            
        }
        else
        {
            if(strstr(orig_input,"pastevents execute")!=NULL)
            {
            store(orig_input,last_line,line_count,current_line,path_output,home,line_array);

            }
        }


        char *var=strtok(input_init,delimiter);
        char ** input=(char **)malloc(sizeof(char *)*qt);
        for(int i=0;i<qt;i++)
        input[i]=(char *)malloc(sizeof(char)*qt);
        int num_of_args=0;
        while(var!=NULL)
        {
            strcpy(input[num_of_args++],var);
            var=strtok(NULL,delimiter);
        }
        // strcpy(in)
        // printf("jbdw%s\n",input_init);
        char orig_inp1[qt];
        strcpy(orig_inp1,orig_input);
        for(int i=num_of_args;i<qt;i++)
        input[i]=NULL;
        for(int o=0;o<num_of_args;o++)
        {
            strcpy(orig_input,orig_inp1);
            // printf("%s\n",orig_input);
            // printf("%s\n",input[o]);
        // printf("djbe %s\n",orig_input);
    int found=0;
        for (int i = 0; orig_input[i] != '\0'; i++)
        {
            if (orig_input[i] == '|') 
            {
                found = 1;
                break;
            }
        }
        
        int found1=0;

        for (int i = 0; orig_input[i] != '\0'; i++)
        {
            if (orig_input[i] == '>'||orig_input[i]=='<') 
            {
                found1 = 1;
                break;
            }

        }

            if(found&&found1==0)
        {
            piping(orig_input,last_line,line_count,current_line,path_output,home,line_array,term,home_len,last,last_term,memory,fore_count,count_running,pid_array,0,cmp);
            // printf("udbe\n");
            continue;
        }
        else if(found1&&found==0)
        {
            
            redirect(orig_input,last_line,line_count,current_line,path_output,home,line_array,term,home_len,last,last_term,memory,fore_count,count_running,pid_array,0,cmp);
            continue;

        }
        else if(found1&&found)
        {
            // pipdirect();
            // printf("wjdbw\n");
            pipdirect(orig_input,last_line,line_count,current_line,path_output,home,line_array,term,home_len,last,last_term,memory,fore_count,count_running,pid_array,0,cmp);
            continue;
        }
        

        const char* delim1="&";
        char *u1=(char *)malloc(sizeof(char)*qt);
        strcpy(u1,input[o]);
        // printf("%s\n",u);
        char *str1=strtok(input[o],delim1);
        // str[strlen(str)]='\0';
        char **entries1=(char **)malloc(sizeof(char*)*qt);
        for(int i=0;i<qt;i++)
        {
            entries1[i]=(char *)malloc(sizeof(char)*qt);
        }

        int str_index=0;
        int index1=0;
        int count_amper=0;
    
        while(u1[str_index]!='\0')
        {
            if(u1[str_index++]=='&')
            count_amper++;
        }
        while(str1!=NULL)
        {
            // printf("%s\n",str);
            entries1[index1++]=str1;
            str1=strtok(NULL,delim1);
            // str[strlen(str)]='\0';
        }
        int l;
        // printf("index: %d\n",index1);
        for(l=0;l<(index1-1);l++)
        {

            execute_command(entries1[l],last_line,line_count,current_line,path_output,home,line_array,term,home_len,last,last_term,memory,&fore_count,count_running,pid_array,1,cmp);
            


        }
            if(index1>1)
            {
                if(u1[strlen(u1)-1]=='&')
            execute_command(entries1[l],last_line,line_count,current_line,path_output,home,line_array,term,home_len,last,last_term,memory,&fore_count,count_running,pid_array,1,cmp);
                else
            execute_command(entries1[l],last_line,line_count,current_line,path_output,home,line_array,term,home_len,last,last_term,memory,&fore_count,count_running,pid_array,0,cmp);
            }
            else
            {
                if(count_amper==1)
            {
                // printf("radn\n");
                execute_command(entries1[l],last_line,line_count,current_line,path_output,home,line_array,term,home_len,last,last_term,memory,&fore_count,count_running,pid_array,1,cmp);
            }    
            else
            execute_command(entries1[l],last_line,line_count,current_line,path_output,home,line_array,term,home_len,last,last_term,memory,&fore_count,count_running,pid_array,0,cmp);

                
            }
            continue;        

            // entries1[num_of_args]=NULL;
        // printf("Input entered :%s\n",input);
        const char* delim=" \t";
        char *u=(char *)malloc(sizeof(char)*qt);
        strcpy(u,input[o]);
        // printf("%s\n",u);
        char *str=strtok(input[o],delim);
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
            // store(u,last_line,line_count,current_line,path_output,home,line_array);
            // printf("%d\n",index);
            for(int k=0;k<(index-1);k++)
            warp(entries,home,term,home_len,last,last_term,index,memory,k+1);
        }
        else if(strcmp(entries[0],"peek")==0)
        {
            // store(u,last_line,line_count,current_line,path_output,home,line_array);
            // printf("%d\n",index
            peek(entries,home,term,home_len,last,last_term,index);
        }
        else if(strcmp(entries[0],"pastevents")==0)
        {
            // printf("Hi\n");
            pastevents(entries,input[o],last,line_count,current_line,path_output,home,line_array,index,term,last_term,home_len,index,memory,path_output,count_running,cmp);
            
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
            // printf("%d\n",getpid());
            for(int i=0;i<fore_count;i++)
            {
                // printf("%d\n",fore_pid[i]);
                if(status_proc(pid_array[i])=='S' || status_proc(pid_array[i])=='R')
                {
                    kill(pid_array[i],SIGCONT);
                    signal(SIGINT, handle_sigint);
                    struct sigaction  sa1;
                    sa1.sa_handler= &handle_sigtstp;
                    sa1.sa_flags=SA_RESTART;
                    sigaction(SIGTSTP,&sa1,NULL);
                    int status;
                    waitpid(pid_array[i],&status,WUNTRACED);
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
    signal(SIGINT, handle_sigint);
                    struct sigaction  sa1;
                    sa1.sa_handler= &handle_sigtstp;
                    sa1.sa_flags=SA_RESTART;
                    sigaction(SIGTSTP,&sa1,NULL);


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
            // printf("Hi\n");
            // store(u,last_line,line_count,current_line,path_output,home,line_array);
            double val;
            syst(entries,home,index,term,count_running,u,pid_array,&fore_count,0,cmp,&val);
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
                *cmp=1;
            }
            }
            else if(val==INF)
            {
                // printf("%f\n",val);
                count_running++;
                printf("%d\n",running[count_running-1].pid);
            }            
        }
        
        }

















}



void pastevents(char **entries,char *input,char *last, int line_count,char *current_line,char *output_path,char *home,char **line_array,int num_arg,char *term,char *last_term,int home_len,int num_entries,char *memory,char* path_output,int count_running,int *cmp)
{

    if(num_arg==1)
    {
        display(entries,input,last,line_count,current_line,output_path,home,line_array,0,num_arg);
    }
    else if(strcmp(entries[1],"purge")==0)
    {
        FILE* file=fopen(output_path,"w");
        fclose(file);
    }   
    else if(strcmp(entries[1],"execute")==0)
    {
        char ch1=entries[2][0];
        char ch2=entries[2][1];
        int num;
        if(ch2=='\0')
        {
            num=ch1-48;
        }
        else
        {
            num=ch1-48+(10*(ch2-48));
        }
        // printf("%d\n",num);
        // execute_command()
        
        execute(line_array[line_count-num],path_output,count_running,home,term,home_len,last,last_term,memory,cmp);
        // take_input(line_array[line_count-num],output_path,home,term,home_len,last,last_term,num_entries,memory);

    }
}   