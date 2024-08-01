#ifndef __PIPING_H
#define __PIPING_H



void piping(char *input,char *last_line,int line_count,char* current_line,char* path_output,char *home,char** line_array,char* term,int home_len,char* last,char* last_term,char* memory,int fore_count,int count_running,int* fore_pid,int back,int *cmp);
void execute_command(char *command, char *last_line, int line_count, char *current_line, char *path_output, char *home, char **line_array, char *term, int home_len, char *last, char *last_term, char *memory, int *fore_cou, int count_running, int *pid_array, int back, int *cmp);


#endif