//
// Created by 고승빈 on 2017. 11. 8..
//

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void heartbeat(int no)
{
    printf("Heartbeat. \n");
    sleep(1);
}

int main()
{
    struct sigaction act;
    int i;

    act.sa_flags = SA_RESTART;
    act.__sigaction_u.__sa_handler = heartbeat;

    sigaction(SIGUSR1, & act , NULL);

    for(i = 0; i < 5; ++i)
    {
        raise(SIGUSR1);
    }

    return 0;
}