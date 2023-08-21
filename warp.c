#include "headers.h"


int check_characters(const char *s) {
    if (s[0] == '~' && s[1] == '/') {
        return 1;
    } else {
        return 0;
    }
}


void warp(char **entries,char *home,char *term,int home_len,char *last,char *last_term)
{
    if(strcmp(entries[1],".")==0)
            {
                // printf("Hi\n");
                char *pwd=(char*)malloc(sizeof(char)*100000);
                getcwd(pwd,100000);
                printf("%s\n",pwd);
                return;
            }

            // else if((strcmp(entries[1],".."))==0)
            // {
                
            //     DIR* current_dir=opendir(".");
            //     struct dirent * dr;
                
            //     // int flag=0;
            //     // while((dr=readdir(current_dir))!=NULL)
            //     // {
            //     //     if(strcmp(entries[1],dr->d_name)==0)
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
            else if(strcmp(entries[1],"~")==0)
            {
                chdir(home);
                char * pwd=(char*)malloc(sizeof(char)*100000);
                getcwd(pwd,100000);
                for(int i=strlen(term)-1;i>=0;i--)
                {
                    
                    // else
                    {
                        term[i]='\0';
                    }

                }
                term[0]='~';
                printf("%s\n",pwd);
            
            } 
            else if(check_characters(entries[1]))
            {
                char * new=(char *)malloc(sizeof(char)*100000);
                for(int i=0;i<home_len;i++)
                new[i]=home[i];
                int index=home_len;
                for(int i=1;i<strlen(entries[1]);i++)
                {
                    new[index++]=entries[1][i];
                }
                printf("%s\n",new);
                chdir(new);
                int l=strlen(term);
                for(int i=0;i<l;i++)
                term[i]='\0';

                for(int i=0;i<strlen(entries[1]);i++)
                term[i]=entries[1][i];    

            }
            else if((strcmp(entries[1],"-"))==0)
            {   
                printf("Hi\n");
                chdir(last);
                char * pwd=(char*)malloc(sizeof(char)*100000);
                getcwd(pwd,100000);
                printf("%s\n",pwd);
                int m=strlen(term);
            for(int i=0;i<m;i++)
            {
                term[i]='\0';
            }
            // int m=
            for(int i=0;i<strlen(last_term);i++)
            term[i]=last_term[i];
            }
            else 
            {
                // printf("%s\n",entries[1]);
                if(chdir(entries[1])!=-1)
                {
                    char * pwd=(char*)malloc(sizeof(char)*100000);
                getcwd(pwd,100000);
                    printf("%s\n",pwd);
                if(strlen(pwd)>=home_len)
                {
                    char * new=(char *)malloc(sizeof(char)*100000);
                    for(int i=home_len;i<strlen(pwd);i++)
                    {
                        new[i-home_len]=pwd[i];
                    }
                    char *hom=(char *)malloc(sizeof(char)*100000);
                    for(int i=0;i<home_len;i++)
                    {
                        hom[i]=home[i];
                    }
                    int l=strlen(term);
                    for(int i=l-1;i>0;i--)
                    {
                        term[i]='\0';
                    }
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
                
                
            }
 
}