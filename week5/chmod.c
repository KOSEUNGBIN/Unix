//
// Created by 고승빈 on 2017. 9. 27..
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    char *filename = "afile";

    if(chmod(filename , 0777) == -1)
    {
        fprintf(stderr , "call to chmod filed %s\n" , filename);
        exit(1);
    }

    printf("%s changed mode\n" , filename);

    return 0;
}