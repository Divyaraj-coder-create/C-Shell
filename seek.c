#include "headers.h"

void removeSubstring(char *str, const char *sub) {
    size_t len = strlen(sub);
    char *p = str;

    while ((p = strstr(p, sub)) != NULL) {
        memmove(p, p + len, strlen(p + len) + 1); 
    }
}
int containsSubstring(const char *str, const char *substring) {
    char *found = strstr(str, substring);

    return (found != NULL);
}

int customCompare(const char *str1, const char *str2) {
    const char *dot1 = strchr(str1, '.');
    const char *dot2 = strchr(str2, '.');

    size_t len1 = dot1 ? (size_t)(dot1 - str1) : strlen(str1);
    size_t len2 = dot2 ? (size_t)(dot2 - str2) : strlen(str2);

    return strncmp(str1, str2, len1 < len2 ? len1 : len2);
}

int my_func(char *name1,char* name2,int l)
{
    if(strlen(name1)>=l)
 {  int i=0; 
    for(;i<l;i++)
    {
        if(name1[i]!=name2[i])
        {
            return 0;
        }
    }
    
        if(strlen(name1)>l)
        {
            if(name1[i]=='.')
            return 1;
            else
            return 0;
        }
        else
        return 1;
    
}
return 0;
}


int count=0;

void print_e1(char *path,char *folder,char *orig)
{

    // printf("%s\n",path);
    char *path1=(char *)malloc(sizeof(char)*qt);
    strcpy(path1,path);
    char *init=(char *)malloc(sizeof(char)*qt);
    getcwd(init,qt);
    struct dirent* dr;
    // printf("%s\n",path);
    chdir(path);
    DIR* directory=opendir(path);
    struct stat path_stat;
    if (stat(path, &path_stat) == 0) {
        if (S_ISREG(path_stat.st_mode)) {
            // printf("%s is a regular file.\n", path);
            FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("fopen");
        // return 1;
    }

    char buffer[1024];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytesRead, stdout); // Print to standard output
    }

    fclose(file);
        } else if (S_ISDIR(path_stat.st_mode)) {
            printf("%s is a directory.\n", path);
            chdir(path);
        } else {
            printf("%s is neither a regular file nor a directory.\n", path);
        }
    }
    // chdir(init);
    closedir(directory);
    
}


char* print_e11(char *path,char *folder,char *orig)
{
    char *path1=(char *)malloc(sizeof(char)*qt);
    strcpy(path1,path);
    char *init=(char *)malloc(sizeof(char)*qt);
    getcwd(init,qt);
    struct dirent* dr;
    // printf("%s\n",path);
    chdir(path);
    DIR* directory=opendir(path);
    while((dr=readdir(directory))!=NULL)
    {
        // printf("%s ",dr->d_name);
        int l=strlen(folder);
        if(my_func(dr->d_name,folder,l))
        {
            count++;
            // printf("%s\n",path);
            // printf("%s\n",orig);
            int l=strlen(orig);
            char buf[qt];
            snprintf(folder,qt,"%s/%s",path,dr->d_name);
            return folder;
            // strcat(path,"/");
            removeSubstring(buf,orig);
            // printf(".");
            // printf("%s\n",buf);
            // printf("\n");
            // printf(".%s\n",path);
            
        }
            if(dr->d_type==DT_DIR&&dr->d_name[0]!='.')
            {
                // printf("jdbdjcbdee\n");
                // snprintf(path1,)
                char buf[qt];
                snprintf(buf,qt,"%s/%s",path1,dr->d_name);
                // strcat(path1,"/");
                // strcat(path1,dr->d_name);
                // printf("AA%s\n",path1);
                print_e11(buf,folder,orig);            
            }



    }
    chdir(init);
    closedir(directory);
    
}


void print_e(char *path,char *folder,char *orig)
{
    char *path1=(char *)malloc(sizeof(char)*qt);
    strcpy(path1,path);
    char *init=(char *)malloc(sizeof(char)*qt);
    getcwd(init,qt);
    struct dirent* dr;
    // printf("%s\n",path);
    chdir(path);
    DIR* directory=opendir(path);
    while((dr=readdir(directory))!=NULL)
    {
        // printf("%s ",dr->d_name);
        int l=strlen(folder);
        if(my_func(dr->d_name,folder,l))
        {
            count++;
            // printf("%s\n",path);
            // printf("%s\n",orig);
            int l=strlen(orig);
            char buf[qt];
            snprintf(buf,qt,"%s/%s",path,dr->d_name);
            // strcat(path,"/");
            removeSubstring(buf,orig);
            // printf(".");
            // printf("%s\n",buf);
            // printf("\n");
            // printf(".%s\n",path);
            
        }
            if(dr->d_type==DT_DIR&&dr->d_name[0]!='.')
            {
                // printf("jdbdjcbdee\n");
                // snprintf(path1,)
                char buf[qt];
                snprintf(buf,qt,"%s/%s",path1,dr->d_name);
                // strcat(path1,"/");
                // strcat(path1,dr->d_name);
                // printf("AA%s\n",path1);
                print_e(buf,folder,orig);            
            }



    }
    chdir(init);
    closedir(directory);
    
}


void print_f(char *path,char *folder,char *orig)
{
    // printf("%s\n",path);
    // printf("%s\n",folder);
    // printf("hi\n");
    char *path1=(char *)malloc(sizeof(char)*qt);
    strcpy(path1,path);
    char *init=(char *)malloc(sizeof(char)*qt);
    getcwd(init,qt);
    struct dirent* dr;
    // printf("%s\n",path);
    chdir(path);
    DIR* directory=opendir(path);
    while((dr=readdir(directory))!=NULL)
    {
        // printf("%s ",dr->d_name);
        int l=strlen(folder);
        if(my_func(dr->d_name,folder,l)&&dr->d_type==DT_DIR&&dr->d_name[0]!='.')
        {
            // printf("%s\n",path);
            // printf("%s\n",orig);
            int l=strlen(orig);
            char buf[qt];
            snprintf(buf,qt,"%s/%s",path,dr->d_name);
            // strcat(path,"/");
            removeSubstring(buf,orig);
            // printf(".");
            // printf("%s\n",buf);
            char buf1[qt];
                snprintf(buf1,qt,"%s/%s",path1,dr->d_name);
                // strcat(path1,"/");
                // strcat(path1,dr->d_name);
                // printf("AA%s\n",path1);
                print_f(buf1,folder,orig); 
            // printf("\n");
            // printf(".%s\n",path);
            
        }
        else if(my_func(dr->d_name,folder,l)&&dr->d_name[0]!='.')
        {
            int l=strlen(orig);
            char buf[qt];
            snprintf(buf,qt,"%s/%s",path,dr->d_name);
            // strcat(path,"/");
            removeSubstring(buf,orig);
            printf(".");
            printf("%s\n",buf);
            char buf1[qt];
                snprintf(buf1,qt,"%s/%s",path1,dr->d_name);
                // strcat(path1,"/");
                // strcat(path1,dr->d_name);
                // printf("AA%s\n",path1);
                // print_f(buf1,folder,orig); 
            // printf("\n");
            // printf(".%s\n",path);
        }

    }
    chdir(init);
    closedir(directory);
}

void print_d(char *path,char *folder,char *orig)
{
    // printf("%s\n",path);
    // printf("%s\n",folder);
    // printf("hi\n");
    char *path1=(char *)malloc(sizeof(char)*qt);
    strcpy(path1,path);
    char *init=(char *)malloc(sizeof(char)*qt);
    getcwd(init,qt);
    struct dirent* dr;
    printf("%s\n",path);
    chdir(path);
    DIR* directory=opendir(path);
    while((dr=readdir(directory))!=NULL)
    {
        // printf("%s ",dr->d_name);
        int l=strlen(folder);
        if(my_func(dr->d_name,folder,l)&&dr->d_type==DT_DIR&&dr->d_name[0]!='.')
        {
            // printf("%s\n",path);
            // printf("%s\n",orig);
            int l=strlen(orig);
            char buf[qt];
            snprintf(buf,qt,"%s/%s",path,dr->d_name);
            // strcat(path,"/");
            removeSubstring(buf,orig);
            printf(".");
            printf("%s\n",buf);
            char buf1[qt];
                snprintf(buf1,qt,"%s/%s",path1,dr->d_name);
                // strcat(path1,"/");
                // strcat(path1,dr->d_name);
                // printf("AA%s\n",path1);
                print_d(buf1,folder,orig); 
            // printf("\n");
            // printf(".%s\n",path);
            
        }

    }
    chdir(init);
    closedir(directory);
}


void print(char *path,char *folder,char *orig)
{
    // printf("%s\n",path);
    // printf("%s\n",folder);
    // printf("hi\n");
    char *path1=(char *)malloc(sizeof(char)*qt);
    strcpy(path1,path);
    char *init=(char *)malloc(sizeof(char)*qt);
    getcwd(init,qt);
    struct dirent* dr;
    // printf("%s\n",path);
    chdir(path);
    DIR* directory=opendir(path);
    while((dr=readdir(directory))!=NULL)
    {
        // printf("%s ",dr->d_name);
        int l=strlen(folder);
        if(my_func(dr->d_name,folder,l))
        {
            // printf("%s\n",path);
            // printf("%s\n",orig);
            int l=strlen(orig);
            char buf[qt];
            snprintf(buf,qt,"%s/%s",path,dr->d_name);
            // strcat(path,"/");
            removeSubstring(buf,orig);
            printf(".");
            printf("%s\n",buf);
            // printf("\n");
            // printf(".%s\n",path);
            
        }
            if(dr->d_type==DT_DIR&&dr->d_name[0]!='.')
            {
                // printf("jdbdjcbdee\n");
                // snprintf(path1,)
                char buf[qt];
                snprintf(buf,qt,"%s/%s",path1,dr->d_name);
                // strcat(path1,"/");
                // strcat(path1,dr->d_name);
                // printf("AA%s\n",path1);
                print(buf,folder,orig);            
            }



    }
    chdir(init);
    closedir(directory);
}



void seek(char **entries, int num_entries,char* home)
{
    struct dirent* dr;
        char *pres=present_dir();
    if(num_entries==2)
    {
        char pres1[qt];
        strcpy(pres1,pres);
        // printf("%sekn\n",pres);
        print(pres,entries[1],pres1);
        // printf("byre\n");
    }
    else if(num_entries==3)
    {
        if(strcmp(entries[1],"-d")==0)
        {
            char pres1[qt];
        strcpy(pres1,pres);
        // printf("%sekn\n",pres);
        print_d(pres,entries[2],pres1);
        }
        else if(strcmp(entries[1],"-f")==0)
        {
            char pres1[qt];
        strcpy(pres1,pres);
        // printf("%sekn\n",pres);
        print_f(pres,entries[2],pres1);
        }
        else if(strcmp(entries[1],"-e")==0)
        {
            char pres1[qt];
        strcpy(pres1,pres);
        char store1[qt],store2[qt],store3[qt];
        strcpy(store1,pres);
        strcpy(store2,pres);
        strcpy(store3,pres);

        // printf("%sekn\n",pres);
        print_e(pres,entries[2],pres1);
        if(count==1)
        {
        char* ret=print_e11(store1,entries[2],pres1);
        char pres1[qt];
        strcpy(pres1,pres);
        // printf("%sekn\n",pres);
        print_e1(ret,entries[2],pres1);
        count=0;

        }
        }
        else if(entries[2][0]=='~')
        {
            char new[qt];
            strcpy(new,home);
            strcat(new,entries[2]);
            char pres1[qt];
            strcpy(pres1,new);
            print(new,entries[1],pres1);
        }
        else 
        {
            chdir(entries[2]);
            char pres1[qt];
            strcpy(pres1,entries[2]);
            print(entries[2],entries[1],pres1);
            chdir(pres);
        }

    }
    else if(num_entries==4)
    {
        if((strcmp(entries[1],"-d")==0&&strcmp(entries[2],"-e")==0)||(strcmp(entries[1],"-e")==0&&strcmp(entries[2],"-d")==0))
        {
            
        }
    }

}