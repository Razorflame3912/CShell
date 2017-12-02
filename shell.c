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

char * strsepstr(char ** s, char * delim){
  char * found = strstr(*s,delim);
  //printf("[%s]",found);
  char * ret = *s;
  if(!found){
    *s = NULL;
    return ret;
  }
  //printf("%s\n",found);
  int i = 0;
  for(i;i<strlen(delim);i++){
    found[i] = NULL;
  }
  i+=1;
  i -= 1;
  *s = found + i;
  return ret;
  
}

void exec_args (char * line){
  char * line2 = (char*)malloc(200);
  char * line3 = strcpy(line2, line);
  char ** arr = (char**)malloc(6 * sizeof(char*));
  int i = 0;
  if(strncmp(line3,"exit",4) == 0){
      exit(0);
  }
  else if(strncmp(line3,"cd ",3) == 0){
    strsep(&line3, " ");
    chdir(line3);
  }
  while(line3){
    arr[i] = strsep(&line3," ");
    i++;
  }
  arr[i] = NULL;
  int f = fork();
  if(!f){
  execvp(arr[0],arr);
  }
}

void redirout (char * line){ //takes potential redirect string
  char * line2 = (char*)malloc(200);
  char * line3 = strcpy(line2, line);
  char ** arr = (char**)malloc(6 * sizeof(char*));
  int i = 0;
  //redirect stdout
  while(line3){
    arr[i] = strsepstr(&line3," > ");
    i++;
  }
  arr[i] = NULL;
  /* i=0;
  for(i;arr[i];i++){
    printf("%s\n",arr[i]);
  }*/
  i=0;
  for(i;arr[i];i++){
    int status;
    int file = open(arr[i+1],O_CREAT | O_WRONLY, 0666);
    int newstdout = dup(1);
    dup2(file,1);
    int f = fork();
    if(f){
      wait(&status);
    }
    else{
    exec_args(arr[i]);
    }
    dup2(newstdout,1);
    close(newstdout);
  }
  
}


void redirin (char * line){ //takes potential redirect string
  char * line2 = (char*)malloc(200);
  char * line3 = strcpy(line2, line);
  char ** arr = (char**)malloc(6 * sizeof(char*));
  int i = 0;
  //redirect stdout
  while(line3){
    arr[i] = strsepstr(&line3," < ");
    i++;
  }
  arr[i] = NULL;
  /* i=0;
  for(i;arr[i];i++){
    printf("%s\n",arr[i]);
  }*/
  i=0;
  for(i;arr[i];i++){
    int status;
    int file = open(arr[i+1],O_CREAT | O_RDONLY, 0666);
    int newstdin = dup(0);
    dup2(file,0);
    int f = fork();
    if(f){
      wait(&status);
    }
    else{
    exec_args(arr[i]);
    }
    dup2(newstdin,0);
    close(newstdin);
  }
}
  

void multi_exec (char * line){
  char * line2 = (char*)malloc(200);
  char * line3 = strcpy(line2, line);
  int status;
  while(line3){
    if(strstr(line3,">")){
      redirout(strsepstr(&line3," ; "));
    }
    else{
      redirin(strsepstr(&line3," ; "));
    }
    wait(&status);
  }
}





int main(){
  /*char line[100] = "wow-this-is-cool";
  char *s1 = line;
  printf("[%s]\n", strsep( &s1, "z" ));
  printf("[%s]\n", s1);

  char line2[100] = "ls -a -l ; woah";
  char *s2 = line2;
  printf("[%s]\n", strsepstr( &s2, " ; " ));
  printf("[%s]\n", s2);*/
  
  while(1){
    int status;
    char * input = (char *)malloc(200);
    int dir = fork();
    if(!dir){
      execlp("pwd","pwd",NULL);
    }
    else{
      wait(&status);
    }
    printf("CShell$ ");
    scanf(" %[^\t\n]s", input);
    //printf("[%s]\n", input);
    multi_exec(input);
  }
  
  return 0;
}
