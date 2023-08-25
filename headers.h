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
// #include "math.h"
#include "pastevents.h"
#include "syst.h"
#include "pwd.h"
#include "grp.h"
#include "time.h"
#include "sys/time.h"
#include "seek.h"
#define MAX_LINE_LENGTH 4096
#define MAX_ENTRIES 4096
#define qt 4096
#define INF -12345
// struct process_running;

 


void store(char *input,char *last,int line_count,char* current_line,char *output_path,char *home,char **line_array);
void take_input(char *inp,char *path_output,char *home,char *term,int home_len,char *last,char *last_term,int num_entries,char *memory);



#endif