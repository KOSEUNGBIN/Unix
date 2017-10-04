//
// Created by 고승빈 on 2017. 9. 27..
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char * usage = "usage : move file1 file2\n";

int main(int argc , char **argv)
{
    if(argc != 3)
    {
        fprintf(stderr , usage);    exit(1);
    }

    if(link(argv[1] , argv[2]) == -1)
    {
        perror("link failed");
        exit(1);
    }

    if(unlink(argv[1]) == -1)
    {
        perror("unlink failed");
        unlink(argv[2]);
        exit(1);
    }

    printf("Succeeded\n");

    return 0;
}