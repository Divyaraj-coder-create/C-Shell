#ifndef HEADERS_H_
#define HEADERS_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include "prompt.h"
#include "warp.h"
#include "peek.h"
#include "proclore.h"
// #include "limits.h"
// #include "math.h"
#include "pastevents.h"
#include "syst.h"
#include "pwd.h"
#include "grp.h"
#include "time.h"
#include "sys/time.h"
#include "seek.h"
#include "redirect.h"
#include "piping.h"
#include "fcntl.h"
#include "activities.h"
#include "signal.h"
#include "signall.h"
#include "termio.h"
#include <ctype.h>
#include "termios.h"
#include "neonate.h"
#include "iman.h"
#include "netdb.h"
#include <arpa/inet.h>
#include "sys/socket.h"
#include "pipdirect.h"
#define MAX_LINE_LENGTH 4096
#define MAX_ENTRIES 4096
#define qt 4096
#define INF -12345
// struct process_running;
extern int cmp;
 extern int fore;
extern int fore_pid;
extern int pid_neel;
void store(char *input,char *last,int line_count,char* current_line,char *output_path,char *home,char **line_array);

void take_input(char *inp,char *path_output,char *home,char *term,int home_len,char *last,char *last_term,int num_entries,char *memory)
;
void handle_sigint(int sig,int *fore_pid,int fore_count);
void handle_sigtstp(int sig);
void bring_to_foreground(pid_t pid);
struct process_running
{
    pid_t pid;
    bool status;
};

extern int std_out,std_in;

extern struct process_running* running;
#endif