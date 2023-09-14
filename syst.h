#ifndef __SYST_H
#define __SYST_H


void sigint_handler(int signum);

void syst(char ** entries,char *home,int len,char *term,int num_running,char *input,int *fore_pi,int *fo,int back,int *cmp,double* syst_ret)
;

#endif