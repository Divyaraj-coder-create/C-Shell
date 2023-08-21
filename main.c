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

void take_input(char *inp,char *path_output,char *home,char *term,int home_len,char *last,char *last_term)
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
            warp(entries,home,term,home_len,last,last_term);
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
            pastevents(entries,input,last,line_count,current_line,path_output,home,line_array,index,term,last_term,home_len);
            
        }
        else if(strcmp(entries[0],"exit")==0)
        {
            // store(u,last_line,line_count,current_line,path_output,home,line_array);
             return;
        }
        return ;

}



int main()
{
    char * path_output=(char *)malloc(sizeof(char)*qt);
    char* home=(char*)malloc(sizeof(char)*qt);
    int home_len=0;
    getcwd(home,qt);
    strcpy(path_output,home);
    strcat(path_output,"/pastevents.txt");
    home_len=strlen(home);
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
    // Keep accepting commands
    while (1)
    {
        
        // Print appropriate prompt with username, systemname and directory before accepting input
        prompt();
        printf("%s>",term);
        char input[4096];
        fgets(input, 4096, stdin);
        int len=strlen(input);
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
        const char* delim=" |\t|;|&";
        char *u=(char *)malloc(sizeof(char)*qt);
        strcpy(u,input);
        char *str=strtok(input,delim);
        // str[strlen(str)]='\0';
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
            str=strtok(NULL,delim);
            // str[strlen(str)]='\0';
        }
        strcpy(input,u);
        // entries[index]=NULL;
        // for(int i=index;i<qt;i++)
        // entries[i]=NULL;
        if(strcmp(entries[0],"warp")==0)
        {
            store(u,last_line,line_count,current_line,path_output,home,line_array);
            warp(entries,home,term,home_len,last,last_term);
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
            pastevents(entries,input,last,line_count,current_line,path_output,home,line_array,index,term,last_term,home_len);
            
        }
    // else if(strcmp(entries))
        else 
        {
            // printf("Hi\n");
            store(u,last_line,line_count,current_line,path_output,home,line_array);
            double val=syst(entries,home,index,term);
            // if(val==INF)
            
            // break;
        }
        
    }
}

