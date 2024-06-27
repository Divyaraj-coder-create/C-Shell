#include "headers.h"


void display(char **entries,char *input,char *last,int line_count,char* current_line,char *output_path,char *home,char **line_array,int num,int num_arg)
{
    if(num_arg==1)
    {FILE *file = fopen(output_path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return ;
    }

    char line[qt]; // Buffer to hold each line

    // Read and print each line until the end of the file
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line); // Print the line
    }

    // Close the file
    fclose(file);}
    
}



void pastevents(char **entries,char *input,char *last, int line_count,char *current_line,char *output_path,char *home,char **line_array,int num_arg,char *term,char *last_term,int home_len,int num_entries,char *memory)
{
    if(num_arg==1)
    {
        display(entries,input,last,line_count,current_line,output_path,home,line_array,0,num_arg);
    }
    else if(strcmp(entries[1],"purge")==0)
    {
        FILE* file=fopen(output_path,"w");
        fclose(file);
    }
    else if(strcmp(entries[1],"execute")==0)
    {
        char ch1=entries[2][0];
        char ch2=entries[2][1];
        int num;
        if(ch2=='\0')
        {
            num=ch1-48;
        }
        else
        {
            num=ch1-48+(10*(ch2-48));
        }
        printf("%d\n",num);
        take_input(line_array[line_count-num],output_path,home,term,home_len,last,last_term,num_entries,memory);

    }
}   