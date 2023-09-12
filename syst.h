#ifndef __SYST_H
#define __SYST_H



double syst(char ** entries,char *home,int len,char *term,int num_running,char *input,int *fore_pid,int *fore_count);
void sigint_handler(int signum);

#endif