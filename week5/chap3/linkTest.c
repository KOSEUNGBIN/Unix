//
// Created by 고승빈 on 2017. 10. 1..
//

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc , char ** argv)
{
    if(argc != 3)
        fprintf(stderr , "Usage : ./linkTest originPath newPath\n");

    if(link(argv[1] , argv[2]) == -1)
    {
        perror("link failed");
        exit(1);
    }

    return 0;
}