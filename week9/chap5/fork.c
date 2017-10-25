//
// Created by 고승빈 on 2017. 10. 25..
//

#include <unistd.h>
#incldue <stdio.h>
int main(int arc , char ** argv){

    pid_t pid;
    printf("Calling fork()\n");
    pid = fork();
    if(pid > 0)
    {
        printf("Parent PIDs : %d , %d , %d\n" , pid, getpid() , getppid());
    }
    else if(pid == 0)
    {
        printf("Child PIDs : %d , %d , %d\n" , pid, getpid() , getppid());
    }
    else
        printf("fork() err.\n");

    return 0;

}