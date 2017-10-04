//
// Created by 고승빈 on 2017. 9. 20..
//

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define NAMELENGTH 41
#define NROOMS  10


char namebuf[NAMELENGTH];
int infile = -1;

char* getOccupier(int roomno);

void main()
{
    int j;
    char  *p;

    for(j = 1 ; j <= NROOMS ; ++j)
    {
        if(p = getOccupier(j))
        {
            printf("Room %2d, %s\n", j , p);
        }
        else
        {
            printf("Error on room %d\n" , j);
        }
    }
}

char* getOccupier(int roomno)
{
    off_t offset;
    ssize_t nread;

    if(infile == -1 && (infile = open("residents", O_RDWR) == -1))
    {
        return NULL;
    }

    offset = (roomno - 1) * NAMELENGTH;

    if(lseek(infile , offset , SEEK_SET) == -1) return NULL;

    if((nread = read(infile , namebuf , NAMELENGTH)) == -1) return NULL;

    namebuf[nread - 1] = '\0';
    return namebuf;
}
