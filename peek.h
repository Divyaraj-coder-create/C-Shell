#ifndef __PEEK_H
#define __PEEK_H



void peek(char **entries,char *home,char *term,int home_len,char *last,char *last_term,int num_arg);
char *present_dir();
int compare(const void *a, const void *b);
void exc(char **entries);
int num(char **str);
char* get_mode_string(__mode_t mode,char *mode_string);
int compare_names(const void *a, const void *b);
int compare_s(const void *a, const void *b);
void exc_l(char **entries,int f);
void exc_la(char **entries,int f);
void exc_a(char **entries);
int check_characters(const char *s);
#endif