//
// Created by 고승빈 on 2017. 10. 1..
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

short lsoct(const char * modeC);
static char permission[10] = "rwxrwxrwx";

int main(int argc , char ** argv)
{
    int i;
    mode_t mode , curMode = 64;

    if(argc != 3)
    {
        fprintf(stderr , "Usage : 3-7 < file name > < mode > \n");
        exit(1);
    }

    if(access(argv[1] , F_OK) == -1)
    {
        fprintf(stderr , "Not Found %s File\n" , argv[1]);
        exit(1);
    }
    if(strlen(argv[2]) != 9 && strlen(argv[2]) != 3 )
    {
        fprintf(stderr , "Option Usage : rwx-wx--- or 730 \n");
        exit(1);
    }

    if(strlen(argv[2]) == 9)    mode = lsoct(argv[2]);
    if(strlen(argv[2]) == 3){
        for(i = 0 ; i < 3; ++i)
        {
            mode += (curMode * (argv[2][i] - 48));
            curMode /= 8;
        }
    }

    if(chmod(argv[1] , mode) == -1)    perror("ERROR : ");

    printf("Change Mode %o\n" , mode);

    exit(0);
}

short lsoct(const char * modeC)
{
    short i , j , index, result = 0 , curPermission = 256;
    for(i = 0 ; i < 3 ; ++i)
    {
        for(j = 0 ; j < 3 ; ++j)
        {
            index = 3 * i + j;
            if(modeC[index] != '-') result += curPermission;
            curPermission /= 2;
        }
    }

    return result;
}

