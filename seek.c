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
        if(strncmp(dr->d_name,folder,l)==0)
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
                strcat(path1,"/");
                strcat(path1,dr->d_name);
                // printf("AA%s\n",path1);
                print(path1,folder,orig);            
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
        if(entries[2][0]=='~')
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

}