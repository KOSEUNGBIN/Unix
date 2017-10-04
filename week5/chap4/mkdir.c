//
// Created by 고승빈 on 2017. 10. 4..
//

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc , char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr , "Usage : ./mkdir file-name\n");
        exit(1);
    }

    mkdir(argv[1] , 0777);

    return 0;
}