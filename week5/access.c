//
// Created by 고승빈 on 2017. 9. 27..
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *filename = "afile";

    if(access(filename , R_OK) == -1)
    {
        fprintf(stderr , "User cannot read file %s\n" , filename);
        exit(1);
    }

    printf("%s readable, proceeding\n" , filename);

    return 0;
}