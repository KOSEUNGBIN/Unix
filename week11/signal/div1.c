//
// Created by 고승빈 on 2017. 11. 8..
//

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

static void fpe(int unused)
{
    printf("SIGFPE caught .\n");
    exit(1);
}

int main()
{
    int error;
    signal(SIGFPE , fpe);
    error = 4 / 0;
    return 0;
}