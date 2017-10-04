//
// Created by 고승빈 on 2017. 9. 27..
//

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#define XPERM 0100

int main(int argc , char ** argv)
{
    int k;
    struct stat statbuf;

    for(k = 1 ; k < argc ; ++k)
    {
        if(stat(argv[k] , &statbuf) == -1)
        {
            fprintf(stderr , "addx: couldn't stat %s\n", argv[k]);
            continue;
        }

        statbuf.st_mode |= XPERM;

        /*
         * chmod 함수를 호출해야만, mode 변경이 이루어짐
         * st_mode를 바꾼다고 해서 변경되지 않음
         * */
        if(chmod(argv[k] , statbuf.st_mode) == -1)
        {
            fprintf(stderr , "addx: couldn't change mode for %s\n" , argv[k]);
        }
    }

    return 0;
}