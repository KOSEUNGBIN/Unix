//
// Created by 고승빈 on 2017. 9. 20..
//

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char *workfile = "junk";

int main()
{
    int filedes;

    if((filedes = open(workfile , O_RDONLY)) == -1)
    {
        printf("Couldn't open %s\n", workfile);
        exit(1);
    }

    exit(0);
}