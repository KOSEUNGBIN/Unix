//
// Created by 고승빈 on 2017. 10. 1..
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc , char** argv)
{
    char buf[100];
    if(argc != 3)
    {
        fprintf(stderr , "Usage : ./symlink originfile linkfile\n");
        exit(1);
    }

    if(symlink(argv[1] , argv[2]) == -1)
    {
        perror("Error : ");
    }

    readlink(argv[2] , buf , 100);

    printf("%s\n" , buf);


}