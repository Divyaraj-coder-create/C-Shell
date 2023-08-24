#ifndef __SEEK_H
#define __SEEK_H



void print(char *path,char *folder,char *orig);
void seek(char **entries, int num_entries,char* home);
void removeSubstring(char *str, const char *sub);
int customCompare(const char *str1, const char *str2);
void print_d(char *path,char *folder,char *orig);
#endif