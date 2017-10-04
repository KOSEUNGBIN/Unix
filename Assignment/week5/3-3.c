//
// Created by 고승빈 on 2017. 9. 30..
//

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

short lsoct(const char * modeC);
void octls(const short modeO , char * inputOctls);

static char permission[10] = "rwxrwxrwx";

int main(int argc , char ** argv)
{
    char inputLsoct[10] = "rwxr-xr-x";
    char resultOctls[10] ;
    short inputOctls = 0755;

    octls(inputOctls , resultOctls);

    printf("lsoct : 0%o \n" , lsoct(inputLsoct));
    printf("octls : %s \n" , resultOctls);

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

void octls(const short modeO , char * inputOctls)
{
    int i;
    short modeArr[9] = {
            0400 , 0200 , 0100 ,
            0040 , 0020 , 0010 ,
            0004 , 0002 , 0001
    };

    for(i = 0 ; i < 9 ; ++i)
    {
        if(modeO & modeArr[i])
        {
            inputOctls[i] = permission[i];
        }
        else
        {
            inputOctls[i] = '-';
        }
    }

    inputOctls[i] =  0;
}