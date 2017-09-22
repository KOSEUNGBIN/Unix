//
// Created by 고승빈 on 2017. 9. 20..
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFSIZE 512

int main(int argc , char* argv[])
{
    int filedesc = 0;
    ssize_t nread;
    char buffer[BUFFSIZE];

    if(argc < 2)
    {
        while((nread = read(filedesc , buffer , BUFFSIZE)) > 0)
        {
            write(1 , buffer , nread);
        }
    }
    else
    {
        if((filedesc = open(argv[1] , O_RDONLY)) == -1)
        {
            printf("error can't open %s\n" , argv[1]);
            exit(1);
        }

        while((nread = read(filedesc , buffer , BUFFSIZE)) > 0)
        {
            write(1 , buffer , nread);
        }

        close(filedesc);
    }

    exit(0);


}