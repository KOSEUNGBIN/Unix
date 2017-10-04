//
// Created by 고승빈 on 2017. 9. 27..
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc , char ** argv)
{
    if(argc != 3)
    {
        perror("Usage : ./mv <old> <new> \n");
        exit(-1);
    }

    if(link(argv[1] , argv[2]))
    {
        printf("Link failed. : %s -> %s \n" , argv[1] , argv[2]);
        exit(-2);
    }

    if(unlink(argv[1]))
    {
        printf("UnLink failed. : %s\n" , argv[1]);
        exit(-3);
    }

    printf("File moved: %s -> %s \n" , argv[1] , argv[2]);

    return 0;
}