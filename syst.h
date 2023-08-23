#ifndef __SYST_H
#define __SYST_H


struct process_running
{
    pid_t pid;
    bool status;
};


double syst(char ** entries,char *home,int len,char *term,struct process_running* pr,int num_running,char *input);

#endif