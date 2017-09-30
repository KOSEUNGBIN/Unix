//
// Created by 고승빈 on 2017. 9. 27..
//

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

int my_double_ls(const char * name)
{
    struct dirent *d;
    DIR *dp;

    if((dp = opendir(name)) == NULL)
    {
        return -1;
    }

    while(d = readdir(dp))
    {
        if(d->d_ino != 0)
        {
            printf("%s \n" , d->d_name);
        }
    }

    rewinddir(dp);

    while(d = readdir(dp))
    {
        if(d->d_ino != 0)
        {
            printf("%s \n" , d->d_name);
        }
    }

    closedir(dp);
}

int main(int argc , char ** argv)
{
    my_double_ls(argv[1]);

    return 0;
}