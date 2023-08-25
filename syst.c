#include "headers.h"
// #include "syst.h"

double syst(char ** entries,char *home,int len,char *term,struct process_running* pr,int num_running,char *input)
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
    struct timeval start_time, end_time;

        gettimeofday(&start_time, NULL);
    if(child>0)
    {
        int status;
        // wait(NULL);
        if(brkr==0)
        {
            waitpid(child,&status,0);
        // printf("%d\n",status);
        gettimeofday(&end_time, NULL);

        double execution_time = (end_time.tv_sec - start_time.tv_sec) +
        (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        printf("Execution time: %f seconds\n", execution_time);
        if(execution_time>2.0&&brkr==0)
        {
            return execution_time;
        }
        return -1.0;
        }
        else
        {
            pr[num_running].pid=child;
            pr[num_running].status=true;
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
            strcat(new[i-1]," &");
            // strcat(new,)
            new[i]=NULL;
            char* args[]={"/bin/zsh","-c",input,NULL};
            // printf("%s %s %s\n",perm[0],perm[1]);
            // execvp(,new);
        }
        else
        {
            execvp(entries[0],entries);
        }
    }
    // execvp(directory,entries,);
}