#include "headers.h"



void store(char *input,char *last,int line_count,char* current_line,char *output_path,char *home,char **line_array)
{
    if(last[strlen(last)-1]=='\n')
    last[strlen(last)-1]='\0';
    // printf("%s\n",last);
    if(strcmp(input,last)==0)
    return;
    else
    {

        //  FILE* file = fopen(output_path, "a");
        // if (file == NULL) {
        //     perror("Error opening file");
        //     return 1;
        // }
        
        if (line_count >= 15) {
            FILE *temp_file = fopen(output_path, "w");
            fclose(temp_file);
       FILE* file = fopen(output_path, "a");
            // printf("Hi\n");
            fseek(file, 0, SEEK_SET);
            for(int i=1;i<15;i++)
            fprintf(file, "%s",line_array[i]);
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
       FILE* file = fopen(output_path, "a");
        fprintf(file, "%s\n", input);
            fclose(file);
        }
        
        
    }
}

void take_input(char *inp,char *path_output,char *home,char *term,int home_len,char *last,char *last_term,int num_entries)
{
        char *input;
        int len=strlen(inp);
        input=inp;
        // printf("%d\n",len);
        if(len>0&&input[len-1]=='\n')
        {
            input[len-1]='\0';
        }
        // printf("%s\n",path_output);
        FILE *file = fopen(path_output, "r");

    if (file == NULL) 
    {
        perror("Error opening file");
        return ;
    }
    char current_line[MAX_LINE_LENGTH];
    char last_line[MAX_LINE_LENGTH] = "";
    int line_count = 0;
    // Read each line and update last_line
    char** line_array=(char **)malloc(sizeof(char *)*15);

    for(int i=0;i<15;i++)
    line_array[i]=(char *)malloc(sizeof(char)*qt);

    while (fgets(current_line, sizeof(current_line), file) != NULL) {
        strcpy(last_line, current_line);
        strcpy(line_array[line_count],current_line);
        line_count++;
    }

    fclose(file);
        printf("Input entered :%s\n",input);
        const char* delim=" |\t|;|&";
        char *u=(char *)malloc(sizeof(char)*qt);
        strcpy(u,input);
        char *str=strtok(input,delim);
        str[strlen(str)-1]='\0';
        char **entries=(char **)malloc(sizeof(char*)*qt);
        for(int i=0;i<qt;i++)
        {
            entries[i]=(char *)malloc(sizeof(char)*qt);
        }
        int index=0;
        for(;str!=NULL;)
        {
            // printf("%s\n",str);
            entries[index++]=str;
            // str[strlen(str)-1]='\0';
            str=strtok(NULL,delim);
        }
        // for(int i=index;i<qt;i++)
        // entries[i]=NULL;
        // strcpy(input,u);
        if(strcmp(entries[0],"warp")==0)
        {
            // store(u,last_line,line_count,current_line,path_output,home,line_array);
            printf("Hello\n");
            warp(entries,home,term,home_len,last,last_term,num_entries);
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
            pastevents(entries,input,last,line_count,current_line,path_output,home,line_array,index,term,last_term,home_len,num_entries);
            
        }
        else if(strcmp(entries[0],"exit")==0)
        {
            store(u,last_line,line_count,current_line,path_output,home,line_array);
             return;
        }
        return ;

}



int main()
{
    int count_running=0;
    struct process_running* running=(struct process_running*)malloc(sizeof(struct process_running)*qt);
    for(int i=0;i<qt;i++)
    running[i].status=false;
    int cmp=0;
    char * path_output=(char *)malloc(sizeof(char)*qt);
    char* home=(char*)malloc(sizeof(char)*qt);
    int home_len=0;
    getcwd(home,qt);
    home_len=strlen(home);
    // printf("%s\n",home);
    // strcpy(path_output,home);
    for(int i=0;i<home_len;i++)
    path_output[i]=home[i];
    // printf("%s\n",home);
    strcat(path_output,"/pastevents.txt");
    // printf("%s\n",home);
    // getcwd(home,qt);
    // printf("%s\n",path_output);
    char *term=(char *)malloc(sizeof(char)*qt);
    char *home1=(char *)malloc(sizeof(char)*qt);
    for(int i=0;i<home_len;i++)
    {
        home1[i]=home[i];
    }
    for(int i=0;i<qt;i++)
    {
        if(i==0)
        term[i]='~';
        else
        term[i]='\0';
    }
    // printf("~");

    char *last=(char *)malloc(sizeof(char)*qt);
    char *last_term=(char *)malloc(sizeof(char)*qt);
    // last[0]='~';o
    for(int i=0;i<home_len;i++)
    last[i]=home[i];
    last_term[0]='~';
    // printf("%s\n",home);
    // Keep accepting commands
    while (1)
    {
        
        // Print appropriate prompt with username, systemname and directory before accepting input
        prompt();
        printf("%s>",term);
        if(cmp==1)
        {
                cmp=0;
                char * pwd=(char*)malloc(sizeof(char)*qt);
                    getcwd(pwd,qt);
                    // printf("%s\n",pwd);
                    // printf("%ld %d\n",strlen(pwd),home_len);
                if(strlen(pwd)>=home_len)
                {
                    char * new=(char *)malloc(sizeof(char)*qt);
                    for(int i=home_len;i<strlen(pwd);i++)
                    {
                        new[i-home_len]=pwd[i];
                    }
                    char *hom=(char *)malloc(sizeof(char)*qt);
                    for(int i=0;i<home_len;i++)
                    {
                        hom[i]=home[i];
                    }
                    int l=strlen(term);
                    for(int i=l-1;i>0;i--)
                    {
                        term[i]='\0';
                    }
                    // printf("jved\n");
                    term[0]='~';
                    strcat(term,new);
                    // term=hom;
                    // for(int )
                }

                else
                {
                    int l=strlen(term);
                    for(int i=0;i<l;i++)
                    term[i]='\0';
                    for(int i=0;i<strlen(pwd);i++)
                    {
                        term[i]=pwd[i];
                    }

                }

        }
        char input[4096];
        fgets(input, 4096, stdin);
        int len=strlen(input);
        // printf("%d\n",len);
        if(len>0&&input[len-1]=='\n')
        {
            input[len-1]='\0';
        }
        for(int i=0;i<count_running;i++)
        {

    // if (running[i].pid < 0) {
    //     perror("fork");
    //     exit(EXIT_FAILURE);
    // } else if ( == 0) {
    //     // Child process code
    //     sleep(5); // Simulate some work
    //     exit(EXIT_SUCCESS);
     {
        // Parent process code
        // printf("Child process created with PID: %d\n", pid);

        int status;
        // printf("%d\n",running[i].pid);
        pid_t result = waitpid(running[i].pid, &status,0);
        // printf("%d\n",result);

        if (status == 0) {
            printf("Child process with PID %d is still running.\n", running[i].pid);
        } else if (status == -1) {
            perror("waitpid");
        } else {
            if(running[i].status==true)
            {
                if (WIFEXITED(status)) 
                {
                printf("Process with PID %d has completed with exit status: %d\n", running[i].pid, WEXITSTATUS(status));
                } 
                else if (WIFSIGNALED(status)) 
                {
                printf("Process with PID %d was terminated by signal: %d\n", running[i].pid, WTERMSIG(status));
                }
                running[i].status=false;
            }
            
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
    char current_line[MAX_LINE_LENGTH];
    char last_line[MAX_LINE_LENGTH] = "";
    int line_count = 0;
    // Read each line and update last_line
    char** line_array=(char **)malloc(sizeof(char *)*15);

    for(int i=0;i<15;i++)
    line_array[i]=(char *)malloc(sizeof(char)*qt);

    while (fgets(current_line, sizeof(current_line), file) != NULL) {
        strcpy(last_line, current_line);
        strcpy(line_array[line_count],current_line);
        line_count++;
    }

    fclose(file);
        // printf("Input entered :%s\n",input);
        const char* delim=" |\t|;";
        char *u=(char *)malloc(sizeof(char)*qt);
        strcpy(u,input);
        // printf("%s\n",u);
        char *str=strtok(input,delim);
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
        entries[index]=NULL;
        for(int i=index;i<qt;i++)
        entries[i]=NULL;
        if(strcmp(entries[0],"warp")==0)
        {
            // printf("%s\n",home);
            store(u,last_line,line_count,current_line,path_output,home,line_array);
            warp(entries,home,term,home_len,last,last_term,index);
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
            pastevents(entries,input,last,line_count,current_line,path_output,home,line_array,index,term,last_term,home_len,index);
            
        }
        else if(strcmp(entries[0],"proclore")==0)
        {
            // printf("hi %d\n",index);
            proclore(entries,index,home_len,home);
        }
        else if(strcmp(entries[0],"seek")==0)
        {
            seek(entries,index,home);
        }
        else 
        {
            // printf("Hi\n");
            store(u,last_line,line_count,current_line,path_output,home,line_array);
            double val=syst(entries,home,index,term,running,count_running,u);
            // if(())
            if(val!=INF&&val!=-1)
            {
            // int num=(int)round(val);
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
                strcat(term," ");
                strcat(term,entries[0]);
                strcat(term,": ");
                strcat(term,string);
                strcat(term,"s");
                cmp=1;
            }
            else if(val==INF)
            {
                printf("%f\n",val);
                count_running++;
                printf("%d\n",running[count_running-1].pid);
            }
            
            // break;
        }
        
    }
}

