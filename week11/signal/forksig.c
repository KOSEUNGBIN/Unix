//
// Created by 고승빈 on 2017. 11. 8..
//

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    struct sigaction act;

    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_NOCLDSTOP;
    act.__sigaction_u.__sa_handler = SIG_IGN;

    sigaction(SIGCHLD, &act , NULL);

    pid = fork();

    if(pid > 0)
    {
        sleep(10);
        printf("Parent woke up.\n");
    }

    return 0;
}