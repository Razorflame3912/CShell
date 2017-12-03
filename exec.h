#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/types.h>
#include <dirent.h>

char * strsepstr (char ** s, char * delim);
void exec_args (char * line);
void redirout (char * line);
void redirin (char * line);
void exec_pipe (char * line);
void multi_exec (char * line);