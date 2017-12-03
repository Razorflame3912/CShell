#include "exec.h"

int main(){
  int originalid = getpid();  
  while(1){
    if(getpid() != originalid){
      exit(0);
    }
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
    multi_exec(input);
  }
  
  return 0;
}
