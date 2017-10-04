//
// Created by 고승빈 on 2017. 10. 4..
//

#include <unistd.h>
#include <stdio.h>

int main(int argc , char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr , "Usage : ./mkdir file-name\n");
        exit(1);
    }

    printf("%d\n" , rmdir(argv[1]));

    return 0;
}