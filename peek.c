#include "headers.h"


struct inf
{
    char *perm;
    int hard_links;
    char *usrname;
    char *grp_name;
    int size;
    char *time;
    char *name;
};
int compare_names(const void *a, const void *b) {
    const struct inf *personA = (const struct inf *)a;
    const struct inf *personB = (const struct inf *)b;
    return strcmp(personA->name, personB->name);
}

int compare_s(const void *a, const void *b) {
    const char *stringA = *(const char **)a;
    const char *stringB = *(const char **)b;
        return strcmp(stringA, stringB);
    
}

char *present_dir()
{
    char *pwd=(char *)malloc(sizeof(char)*qt);
    getcwd(pwd,qt);
    return pwd;
}

char* get_mode_string(__mode_t mode,char *mode_string) {
    //  char mode_string[11];
    mode_string[0] = (S_ISDIR(mode)) ? 'd' : '-';
    mode_string[1] = (mode & S_IRUSR) ? 'r' : '-';
    mode_string[2] = (mode & S_IWUSR) ? 'w' : '-';
    mode_string[3] = (mode & S_IXUSR) ? 'x' : '-';
    mode_string[4] = (mode & S_IRGRP) ? 'r' : '-';
    mode_string[5] = (mode & S_IWGRP) ? 'w' : '-';
    mode_string[6] = (mode & S_IXGRP) ? 'x' : '-';
    mode_string[7] = (mode & S_IROTH) ? 'r' : '-';
    mode_string[8] = (mode & S_IWOTH) ? 'w' : '-';
    mode_string[9] = (mode & S_IXOTH) ? 'x' : '-';
    mode_string[10] = '\0';
    return mode_string;
    // return mode_string;
}


int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void exc(char **entries)
{
chdir(entries[1]);
        DIR* pwd=opendir(present_dir());
        struct dirent* inside;
        char **dir_list=(char **)malloc(sizeof(char *)*qt);
        for(int i=0;i<qt;i++)
        dir_list[i]=(char*)malloc(sizeof(char)*qt);
        int ind=0;
        while((inside=readdir(pwd))!=NULL)
        {
            if(inside->d_name[0]=='.')
            continue;
            strcpy(dir_list[ind++],inside->d_name);
        }
        qsort(dir_list,ind,sizeof(char *),compare);
        for (int i = 0; i < ind; i++)
        {
        printf("%s\n", dir_list[i]);
        // free(dir_list[i]);
        }

}
void exc_a(char **entries)
{
    chdir(entries[2]);
        DIR* pwd=opendir(present_dir());
        struct dirent* inside;
        char **dir_list=(char **)malloc(sizeof(char *)*qt);
        for(int i=0;i<qt;i++)
        dir_list[i]=(char*)malloc(sizeof(char)*qt);
        int ind=0;
        while((inside=readdir(pwd))!=NULL)
        {
            // if(inside->d_name[0]=='.')
            // continue;
            strcpy(dir_list[ind++],inside->d_name);
        }
        qsort(dir_list,ind,sizeof(char *),compare_s);
        for (int i = 0; i < ind; i++)
        {
        printf("%s\n", dir_list[i]);
        // free(dir_list[i]);
        }

}
void exc_l(char **entries,int f)
{
    chdir(entries[f]);
            DIR* pwd=opendir(present_dir());
        struct dirent* inside;
        struct inf * files=(struct inf *)malloc(sizeof(struct inf)*qt);
        for(int i=0;i<qt;i++)
        {
            files[i].grp_name=(char *)malloc(sizeof(char)*qt);
            files[i].name=(char *)malloc(sizeof(char)*qt);
            files[i].perm=(char *)malloc(sizeof(char)*qt);
            files[i].time=(char *)malloc(sizeof(char)*qt);
            files[i].usrname=(char *)malloc(sizeof(char)*qt);

        }
        int ind=0;
        while((inside=readdir(pwd))!=NULL)
        {
            if (strcmp(inside->d_name, ".") == 0 || strcmp(inside->d_name, "..") == 0) {
            continue;}
            else if(inside->d_name[0]=='.')
            continue;
            strcpy(files[ind++].name,inside->d_name);
        }
        qsort(files,ind,sizeof(struct inf),compare_names);
        struct stat file_stat;
        for(int i=0;i<ind;i++)
        {
            lstat(files->name,&file_stat);
            struct passwd *user_info = getpwuid(file_stat.st_uid);
        struct group *group_info = getgrgid(file_stat.st_gid);
        // printf("%d\n",file_stat.st_mode);
        // char date_string[20];
        // char *time=ctime(&file_stat.st_mtime);
        // time[strlen(time)-1]='\0';
        // printf("")
        char date_time_string[20];
        // char date_time_string[20];
        strftime(date_time_string, sizeof(date_time_string), "%d %b", localtime(&file_stat.st_atime));
        char *tm=ctime(&file_stat.st_mtime);
        tm[strlen(tm)-1]='\0';
        char *mode_string=(char *)malloc(sizeof(char)*11);
        strftime(files[i].time, sizeof(files[i].time), "%b %d %H:%M", localtime(&file_stat.st_mtime));
        printf("%s %ld %s %s %lld %s %s\n",
               get_mode_string(((__mode_t)file_stat.st_mode),mode_string),
               file_stat.st_nlink,
               user_info->pw_name,
               group_info->gr_name,
               (long long)file_stat.st_size,
               tm,
               files[i].name);

        }
        
}
void exc_la(char **entries,int f)
{
    chdir(entries[f]);
            DIR* pwd=opendir(present_dir());
        struct dirent* inside;
        struct inf * files=(struct inf *)malloc(sizeof(struct inf)*qt);
        for(int i=0;i<qt;i++)
        {
            files[i].grp_name=(char *)malloc(sizeof(char)*qt);
            files[i].name=(char *)malloc(sizeof(char)*qt);
            files[i].perm=(char *)malloc(sizeof(char)*qt);
            files[i].time=(char *)malloc(sizeof(char)*qt);
            files[i].usrname=(char *)malloc(sizeof(char)*qt);

        }
        int ind=0;
        while((inside=readdir(pwd))!=NULL)
        {
            
            
            strcpy(files[ind++].name,inside->d_name);
        }
        qsort(files,ind,sizeof(struct inf),compare_names);
        struct stat file_stat;
        for(int i=0;i<ind;i++)
        {
            lstat(files->name,&file_stat);
            struct passwd *user_info = getpwuid(file_stat.st_uid);
        struct group *group_info = getgrgid(file_stat.st_gid);
        // printf("%d\n",file_stat.st_mode);
        // char date_string[20];
        // char *time=ctime(&file_stat.st_mtime);
        // time[strlen(time)-1]='\0';
        // printf("")
        char date_time_string[20];
        // char date_time_string[20];
        strftime(date_time_string, sizeof(date_time_string), "%d %b", localtime(&file_stat.st_atime));
        char *tm=ctime(&file_stat.st_mtime);
        tm[strlen(tm)-1]='\0';
        char *mode_string=(char *)malloc(sizeof(char)*11);
        strftime(files[i].time, sizeof(files[i].time), "%b %d %H:%M", localtime(&file_stat.st_mtime));
        printf("%s %ld %s %s %lld %s %s\n",
               get_mode_string(((__mode_t)file_stat.st_mode),mode_string),
               file_stat.st_nlink,
               user_info->pw_name,
               group_info->gr_name,
               (long long)file_stat.st_size,
               tm,
               files[i].name);

        }
}
int num(char **str)
{
    int num=0;
    while(str[num]!=NULL)
    {
        num++;
    }
    return num;
}

void peek(char **entries,char *home,char *term,int home_len,char *last,char *last_term,int num_arg)
{
    // printf("%d\n",(sizeof(entries)/sizeof(entries[0])));
    if(num_arg==1)
    {        
        exc(entries);
    }
    else 
    {
        char *present=present_dir();
        if(strcmp(entries[1],"~")==0)
            {
                chdir(home);
                exc(entries);
            }
        else if(check_characters(entries[1]))
            {
                char * new=(char *)malloc(sizeof(char)*qt);
                for(int i=0;i<home_len;i++)
                new[i]=home[i];
                int index=home_len;
                for(int i=1;i<strlen(entries[1]);i++)
                {
                    new[index++]=entries[1][i];
                }
                printf("%s\n",new);
                chdir(new);
                exc(entries);
            }
        else if(strcmp(entries[1],"-la")==0||strcmp(entries[1],"-al")==0||(strcmp(entries[1],"-a")==0&&strcmp(entries[2],"-l")==0)||(strcmp(entries[1],"-l")==0&&strcmp(entries[2],"-a")==0))
        {
            if(strcmp(entries[1],"-la")==0||strcmp(entries[1],"-al")==0)
            {
                exc_la(entries,2);
            }
            else
            {
                exc_la(entries,3);
            }
        }
        
        else if(strcmp(entries[1],"-l")==0)
        {
            chdir(entries[2]);
            DIR* pwd=opendir(present_dir());
        struct dirent* inside;
        struct inf * files=(struct inf *)malloc(sizeof(struct inf)*qt);
        for(int i=0;i<qt;i++)
        {
            files[i].grp_name=(char *)malloc(sizeof(char)*qt);
            files[i].name=(char *)malloc(sizeof(char)*qt);
            files[i].perm=(char *)malloc(sizeof(char)*qt);
            files[i].time=(char *)malloc(sizeof(char)*qt);
            files[i].usrname=(char *)malloc(sizeof(char)*qt);

        }
        int ind=0;
        while((inside=readdir(pwd))!=NULL)
        {
            
            if (strcmp(inside->d_name, ".") == 0 || strcmp(inside->d_name, "..") == 0) {
            continue;}
            else if(inside->d_name[0]=='.')
            continue;
            strcpy(files[ind++].name,inside->d_name);
        }
        qsort(files,ind,sizeof(struct inf),compare_names);
        struct stat file_stat;
        for(int i=0;i<ind;i++)
        {
            lstat(files->name,&file_stat);
            struct passwd *user_info = getpwuid(file_stat.st_uid);
        struct group *group_info = getgrgid(file_stat.st_gid);
        // printf("%d\n",file_stat.st_mode);
        // char date_string[20];
        // char *time=ctime(&file_stat.st_mtime);
        // time[strlen(time)-1]='\0';
        // printf("")
        char date_time_string[20];
        // char date_time_string[20];
        strftime(date_time_string, sizeof(date_time_string), "%d %b", localtime(&file_stat.st_atime));
        char *tm=ctime(&file_stat.st_mtime);
        tm[strlen(tm)-1]='\0';
        char *mode_string=(char *)malloc(sizeof(char)*11);
        strftime(files[i].time, sizeof(files[i].time), "%b %d %H:%M", localtime(&file_stat.st_mtime));
        printf("%s %ld %s %s %lld %s %s\n",
               get_mode_string(((__mode_t)file_stat.st_mode),mode_string),
               file_stat.st_nlink,
               user_info->pw_name,
               group_info->gr_name,
               (long long)file_stat.st_size,
               tm,
               files[i].name);
        }
        
        }    

        else if(strcmp(entries[1],"-a")==0)
        {
            exc_a(entries);
        }
        else    
        {   
            chdir(entries[1]);
            exc(entries);
        }
        chdir(present);
    }
}