//
// Created by 고승빈 on 2017. 11. 8..
//

#include <stdio.h>
#include <signal.h>

void fpe(int unused){
    printf("SIGFPE caught.\n");
}

int main()
{
    int error;
    struct sigaction act;

    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_RESETHAND;
    act.__sigaction_u.__sa_handler = fpe;
    sigaction(SIGFPE, &act, NULL);

    error = 4 / 0;

    return 0;
}