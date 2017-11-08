//
// Created by 고승빈 on 2017. 11. 8..
//

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    pid_t pid;
    pid = fork();

    if(pid == 0)
    {
        kill(getppid(), SIGKILL);
        printf("I killed parent.\n");
    }
    else if(pid > 0)
    {
        sleep(10);
        printf("You Immoral!!\n");
    }

    return 0;
}