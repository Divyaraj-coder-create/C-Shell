#include "headers.h"




void warp(char **entries,char *home,char *term,int home_len,char *last,char *last_term,int num_entries,char *memory,int k)
{
    // printf("%d\n",num_entries);
    // printf("%s\n",entries[0]);
    // printf("Mem: %s\n",memory);

    if(num_entries==1)
    {
        // printf("%s\n",home);
                strcpy(memory,present_dir());
                chdir(home);
                char * pwd=(char*)malloc(sizeof(char)*qt);
                getcwd(pwd,qt);
                for(int i=strlen(term)-1;i>=0;i--)
                {
                    
                    {
                        term[i]='\0';
                    }
                }
                term[0]='~';
                printf("%s\n",pwd);

    }

    else if(strcmp(entries[k],".")==0)
        {
                // printf("Hi\n");
                strcpy(memory,present_dir());
                char *pwd=(char*)malloc(sizeof(char)*qt);
                getcwd(pwd,qt);
                printf("%s\n",pwd);
                return;
        }

            // else if((strcmp(entries[k],".."))==0)
            // {
                
            //     DIR* current_dir=opendir(".");
            //     struct dirent * dr;
                
            //     // int flag=0;
            //     // while((dr=readdir(current_dir))!=NULL)
            //     // {
            //     //     if(strcmp(entries[k],dr->d_name)==0)
            //     //     {
            //     //         flag=1;
            //     //         strcat(pwd,"/");
            //     //         strcat(pwd,dr->d_name);
            //     //         printf("%s\n",pwd);
            //     //         // printf("%d\n",strlen(term));
            //     //         int brkr=0;
            //     //         strcat(term,"/");

            //     //         strcat(term,dr->d_name);
            //     //         break;
            //     //         chdir(pwd);
            //     //     }
            //     // }
            //     // if(term)
                
            //     if(term[strlen(term)-1]=='~')
            //     {
            //         chdir("..");
            //     char *pwd=(char*)malloc(sizeof(char)*100000);
            //     getcwd(pwd,100000);
            //     printf("%s\n",pwd);
            //     term[strlen(term)-1]='\0';
            //     strcat(term,pwd);
            //     }
            //     else
            //     {
            //     chdir("..");
            //     char *pwd=(char*)malloc(sizeof(char)*100000);
            //     getcwd(pwd,100000);
            //     printf("%s\n",pwd);
            //     for(int i=strlen(term)-1;i>=0;i--)
            //     {
            //         if(term[i]=='/')
            //         {
            //             term[i]='\0';
            //             break;
            //         }
            //         else
            //         {
            //             term[i]='\0';
            //         }
            //     }
            //     }
                                

            // }
            else if(strcmp(entries[k],"~")==0)
            {
                // printf("%s\n",home);
                strcpy(memory,present_dir());
                chdir(home);
                char * pwd=(char*)malloc(sizeof(char)*qt);
                getcwd(pwd,qt);
                for(int i=strlen(term)-1;i>=0;i--)
                {
                    
                    {
                        term[i]='\0';
                    }
                }
                term[0]='~';
                printf("%s\n",pwd);
            } 
            else if(check_characters(entries[k]))
            {
                strcpy(memory,present_dir());    
                char * new=(char *)malloc(sizeof(char)*qt);
                for(int i=0;i<home_len;i++)
                new[i]=home[i];
                int index=home_len;
                for(int i=1;i<strlen(entries[k]);i++)
                {
                    new[index++]=entries[k][i];
                }
                printf("%s\n",new);
                chdir(new);
                int l=strlen(term);
                for(int i=0;i<l;i++)
                term[i]='\0';

                for(int i=0;i<strlen(entries[k]);i++)
                term[i]=entries[k][i];

            }
            else if((strcmp(entries[k],"-"))==0)
            {   
                printf("%s\n",memory);
                char tmp[qt];
                strcpy(tmp,present_dir());
                chdir(memory);
                if(strncmp(home,memory,home_len)==0)
                {
                    // printf("Hi\n");
                    term[0]='~';
                    int ind=1;
                    for(int i=home_len;i<strlen(memory);i++)
                    {
                        term[ind++]=memory[i];
                    }
                    for(int i=ind;i<qt;i++)
                    term[i]='\0';
                }
                else
                {
                    strcpy(term,memory);
                }
                strcpy(memory,tmp);

            }
            else 
            {
                // printf("%s\n",entries[k]);
                    // strcpy(memory,present_dir());
                    strcpy(memory,present_dir());
                if(chdir(entries[k])!=-1)
                {
                    // printf("%s\n",term);
                    char * pwd=(char*)malloc(sizeof(char)*qt);
                    getcwd(pwd,qt);
                    printf("%s\n",pwd);
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
                
                else
                {
                    printf("ERROR : This is not a valid command\n");
                }
                
                
            }
 
}