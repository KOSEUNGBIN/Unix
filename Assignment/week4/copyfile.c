//
// Created by 고승빈 on 2017. 9. 20..
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 4096
#define PERMISSION 0644

int main(int argc , char * argv[])
{
    char buffer[BUFSIZE];
    int filedescIn , filedescOut;
    ssize_t nread;

    if(argc < 3)
    {
        printf("error arguments count : %d\n" , argc);
        exit(1);
    }

    if((filedescIn = open(argv[1] , O_RDONLY)) == -1)
    {
        printf("error %s doesn't exist\n" , argv[1]);
        exit(1);
    }

    if((filedescOut = open(argv[2] , O_WRONLY | O_CREAT | O_TRUNC , PERMISSION)) == -1)
    {
        printf("error can't open the %s file \n" , argv[2]);
        exit(1);
    }

    while((nread = read(filedescIn , buffer , BUFSIZE)) > 0)
    {
        if(write(filedescOut , buffer , nread) < 0)
        {
            printf("error during coping\n");
            exit(1);
        }
    }

    close(filedescIn);  close(filedescOut);

    exit(0);
}