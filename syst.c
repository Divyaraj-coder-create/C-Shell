#include "headers.h"
// #include "syst.h"



double syst(char ** entries,char *home,int len,char *term,int num_running,char *input,int *fore_pid,int *fore_count)
{

    int brkr=0;
            char **perm=(char **)malloc(sizeof(char *)*(qt+2));
            perm[0]=(char *)malloc(sizeof(char)*(qt));
            perm[1]=(char *)malloc(sizeof(char)*(qt));
            // printf("%d\n",len);
    for(int i=0;i<len;i++)
    {
            if(strcmp(entries[i],"&")==0)
            {
                brkr=1;
                break;
            }
            
    }

        // printf("%d\n",brkr);
        if(brkr)
        {
            perm[0]="sh";
            perm[1]="-c";
            for(int i=2;i<(len+2);i++)
            {
                perm[i]=(char *)malloc(sizeof(char)*(qt));
                strcpy(perm[i],entries[i-2]);
            }
            perm[len+2]=NULL;
        }    
            
    pid_t child=fork();
            fore_pid[(*fore_count)++]=child;
    struct timeval start_time, end_time;

        gettimeofday(&start_time, NULL);
    if(child>0)
    {
        
        int status;
        // wait(NULL);
        if(brkr==0)
        {
            // printf("%d\n",getpid());
            waitpid(child,&status,WUNTRACED);
            fore=0;
            // tcsetpgrp(STDIN_FILENO, getpgrp()); // Restore the terminal's foreground process group
        // child = 0;
        // printf("%d\n",status);
        gettimeofday(&end_time, NULL);
        double execution_time = (end_time.tv_sec - start_time.tv_sec) +
        (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        // printf("Execution time: %f seconds\n", execution_time);
        if(execution_time>2.0&&brkr==0)
        {
            return execution_time;
        }
        
        else if(brkr==0)
        return -1.0;
        }
        else
        {
            running[num_running].pid=child;
            running[num_running].status=true;
            // *num_running++;
            return INF;
        }
        
    }
    else
    {
        // printf("%s\n",entries[0]);
        // execvp(entries[0],entries);
        // printf("hello\n");
        // printf("")
        if(brkr)
        {
            
            char ** new=(char**)malloc(sizeof(char*)*qt);
            for(int i=0;i<qt;i++)
            new[i]=(char *)malloc(sizeof(char)*qt);
            int i;
            for(i=0;i<(len-1);i++)
            new[i]=entries[i];
            // strcat(new[i-1]," &");
            // strcat(new,)
            new[i]=NULL;
            // char* args[]={"/bin/zsh","-c",input,NULL};
            // char buf[qt];
            // snprintf(buf,qt,"%s%s",entries[0],entries[1]);
            // printf("%s %s %s\n",perm[0],perm[1]);
            setpgid(getpid(),getpid());
            execvp(new[0],new);
        }
        else
        {
            // tcsetpgrp(STDIN_FILENO, getpid());
            fore_pid=getpid();            
            fore=1;
            execvp(entries[0],entries);
            
        }
    }
    // execvp(directory,entries,);
}