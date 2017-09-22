//
// Created by 고승빈 on 2017. 9. 20..
//

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 512

void main()
{
    char buffer[BUFSIZE];
    int filedes;

    ssize_t nread;
    long total = 0;

    if((filedes = open( "otherfile", O_RDONLY | O_CREAT , 0777 )) == -1)
    {
        printf("error in opening otherfile \n");
        exit(1);
    }
    while((nread = read(filedes , buffer , BUFSIZE)) > 0)
    {
        total += nread;
    }

    printf("total chars in otherfile : %ld\n", total);
    exit(0);
}