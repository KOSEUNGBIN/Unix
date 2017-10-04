//
// Created by 고승빈 on 2017. 9. 27..
//

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>

int main()
{
    DIR *dp;
    if((dp = opendir("dir1")) == NULL)
    {
        fprintf(stderr , "Error on opening directory dir1 \n");
        exit(1);
    }

    closedir(dp);

    return 0;
}