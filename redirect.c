#include "headers.h"



void redirect(char *command)
{
    char input_file[qt],output_file[qt];
    int f=0;
    for(int i=0;i<strlen(command);i++)
    {
        if(command[i]=='<')
        {
            f=1;
            break;
        }
    }
    if(f)
    {
        char *tokenised_first[qt];
        // char token;
        char *token=strtok(command,"<");
        int ind=0;
        while(token!=NULL)
        {
            tokenised_first[ind++]=token;
            token=strtok(NULL,"<");
        }

        int less=0,greater=0,double_greater=0;
            char* inp_file=(char*)malloc(sizeof(char)*qt);
        if(ind>1)
        {
            less=1;
            // char tmp[qt];
            strcpy(inp_file,tokenised_first[1]);
            char *tmp=strtok(inp_file," \t\r\n");
            strcpy(input_file,tmp);
            strcat(input_file,"\0");
        }
        char new_tok[10];
        int app=0;
        if(strstr(command,">>")!=NULL)
        {
            app=1;
            strcpy(new_tok,">>");
        }
        else 
        {
            strcpy(new_tok,">");
        }
        // printf("hello\n");
        char* new[qt];
        // strcpy(new,tokenised_first[1]);
        // char* y=strtok(new,new_tok);
        int k=0;
        new[0]=strtok(tokenised_first[1],new_tok);
        while(new[k]!=NULL)
        {
            new[++k]=strtok(NULL,new_tok);
        }

    if(k>1)
    {
        greater=1;
        // char tmp[qt];
        strcpy(output_file,new[1]);
        char *tmp=strtok(output_file," \t\r\n");
        strcpy(output_file,tmp);
        strcat(output_file,"\0");
    }

    k=0;
    char *temp2[qt];
    temp2[0]=strtok(tokenised_first[0]," ""\t");
    while(temp2[k]!=NULL)
    {
        temp2[++k]=strtok(NULL," ""\t");
    }

    if(greater&&less)
    {
        int init_input=dup(STDIN_FILENO),init_out=dup(STDOUT_FILENO);
        int child=fork();
        int stat_in=open(input_file,O_RDONLY);
        int stat_out=(app>0)?open(output_file, O_APPEND | O_WRONLY | O_CREAT, 0644):open(output_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
        dup2(stat_out,1);
        if(stat_in<0)
        printf("No such input file found!\n");

        if(child)
        {
            int status;
            while(wait(&status)!=child);
            dup2(init_out,1);
            close(stat_in);
        }
        else
        {
            // if(stat_in>=0)
            {
                dup2(stat_in,0);
                int y=execvp(temp2[0],temp2);
                if(y<0)
                {
                    perror("error\n");
                    dup2(init_out,1);
                    close(stat_in);
                }
                dup2(init_input,0);
            }
        }

    }

    else if(greater)
    {
        int init_out=dup(STDOUT_FILENO);
        int child=fork();
        int stat_out=(app>0)?open(output_file, O_APPEND | O_WRONLY | O_CREAT, 0644):open(output_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
        dup2(stat_out,1);
        int status;
        if (child>0)
        {
            while (wait(&status) != child) {}
            dup2(init_out, 1);
            close(stat_out);
        }
        else
        {
            int y=execvp(temp2[0],temp2);
        if(y<0)
        {
            perror("error\n");
            dup2(init_out,1);
            close(stat_out);
        }            exit(0);
    }
    }

    else
    {
        // printf("divyaraj\n");
        int init_input=dup(STDIN_FILENO);
        int child=fork();
        int stat_in=open(input_file,O_RDONLY);
        if(stat_in<0) 
        printf("No such input file found!\n");
        if(child==0)
        {

            // if(stat_in>=0)
                // printf("%s\n",temp2[1]);
                // printf("%s\n",temp2[0]);
                dup2(stat_in,0);
                int y=execvp(temp2[0],temp2);
                if(y<0)
                {
                perror("error\n");
                dup2(-1,1);
                close(stat_in);
                }
                dup2(init_input,0);
            
            // exit(0);
        }
        else
        {
            int status;
        while (wait(&status) != child);
        }
    }


    }

    else
    {
        char new_tok[10];
        int app=0;
        int greater=0;
        if(strstr(command,">>")!=NULL)
        {
            app=1;
            strcpy(new_tok,">>");
        }
        else 
        {
            strcpy(new_tok,">");
        }
        char* new[qt];
        // strcpy(new,tokenised_first[1]);
        // char* y=strtok(new,new_tok);
        int k=0;
        new[0]=strtok(command,new_tok);
        while(new[k]!=NULL)
        {
            new[++k]=strtok(NULL,new_tok);
        }

    if(k>1)
    {
        greater=1;
        // char tmp[qt];
        strcpy(output_file,new[1]);
        char *tmp=strtok(output_file," \t\r\n");
        strcpy(output_file,tmp);
        strcat(output_file,"\0");
    }
    
    k=0;
    char *temp2[qt];
    temp2[0]=strtok(new[0]," ""\t");
    while(temp2[k]!=NULL)
    {
        temp2[++k]=strtok(NULL," ""\t");
    }
        printf("Hi\n");

    int init_out=dup(STDOUT_FILENO);
        int child=fork();
        int stat_out=(app)?open(output_file, O_APPEND | O_WRONLY | O_CREAT, 0644):open(output_file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
        dup2(stat_out,1);
        int status;
        if (child>0)
        {
            while (wait(&status) != child) {}
            dup2(init_out, 1);
            close(stat_out);
        }
        else
        {
            int y=execvp(temp2[0],temp2);
        if(y<0)
        {
            perror("error\n");
            dup2(init_out,1);
            close(stat_out);
        }            exit(0);
    }
    }

}
