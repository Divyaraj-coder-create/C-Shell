#include "headers.h"


double syst(char ** entries,char *home,int len,char *term)
{
    int brkr=0;
            char **perm=(char **)malloc(sizeof(char *)*(qt+2));
    for(int i=0;i<len;i++)
        {
            if(strcmp(entries[i],"&")==0)
            {
                brkr=1;
                break;
            }
            
        }
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
        waitpid(child,&status,0);
        gettimeofday(&end_time, NULL);

        double execution_time = (end_time.tv_sec - start_time.tv_sec) +
        (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        printf("Execution time: %f seconds\n", execution_time);
        if(execution_time>2.0&&brkr==0)
        {
            return execution_time;
        }
        else if(brkr==1)
        {
            return INF;
        }
        return -1.0;
    }
    else
    {
        // printf("%s\n",entries[0]);
        // execvp(entries[0],entries);
        // printf("hello\n");
        if(brkr)
        {
            execvp(perm[0],perm);
        }
        else
        {
            // printf("hi\n");
            execvp(entries[0],entries);
        }
    }
    // execvp(directory,entries,);
}