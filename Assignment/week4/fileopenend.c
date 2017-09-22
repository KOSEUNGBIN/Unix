//
// Created by 고승빈 on 2017. 9. 20..
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc , char * argv[])
{
    int filedes;
    int openOption;

    if(argc < 3)
    {
        printf("error arguments %d\n" , argc);
        exit(-1);
    }

    if(strcmp(argv[2] , "r" ) == 0)
    {
        openOption = O_RDONLY;
    }
    else if(strcmp(argv[2] , "w" ) == 0)
    {
        openOption = O_WRONLY;
    }
    else if(strcmp(argv[2] , "rw" ) == 0)
    {
        openOption = O_RDWR;
    }
    else if(strcmp(argv[2] , "a" ) == 0)
    {
        openOption = O_WRONLY | O_APPEND;
    }
    else
    {
        printf("error second argument : %s\n" , argv[2]);
        exit(-1);
    }

    if((filedes = open(argv[1] , openOption)) == -1)
    {
        printf("error doesn't open %s file\n" , argv[1]);
        exit(-1);
    }

    printf("filedescriptor : %d\n" , filedes);

    close(filedes);

    exit(0);

}