//
// Created by 고승빈 on 2017. 10. 1..
//

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int main()
{
    int fdisc;

    if((fdisc = open("input" , O_CREAT , 0777)) == -1) fprintf(stderr , "not found\n");

    close(fdisc);

    return 0;
}