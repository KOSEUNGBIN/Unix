//
// Created by 고승빈 on 2017. 9. 30..
//

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc , char ** argv)
{
    int i;
    struct stat buf;
    stat(argv[1] , &buf);

    printf("dev = %d/%d" , major(buf.st_dev) , minor(buf.st_dev));

    if(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
    {
        printf(" (%s) rdev = %d/%d" , (S_ISCHR(buf.st_mode) ? "character" : "block" ) , major(buf.st_rdev) , minor(buf.st_rdev));
    }

    printf("\n");
    exit(0);
}