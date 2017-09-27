//
// Created by 고승빈 on 2017. 9. 27..
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

static short octarray[9] = {
        0400, 0200, 0100,
        0040, 0020, 0010,
        0004, 0002, 0001
};

static char perms[10] = "rwxrwxrwx";

int filedata(const char *pathname)
{
    struct stat statbuf;
    char descript[10];
    int j;

    if(stat(pathname , &statbuf) == -1)
    {
        fprintf(stderr , "Couldn't stat %s\n" , pathname);
        return -1;
    }

    for( j = 0 ; j < 9 ; ++j)
    {
        if(statbuf.st_mode & octarray[j])
        {
            descript[j] = perms[j];
        }
        else
        {
            descript[j] = '-';
        }

        descript[9] = (void *) 0;


    }

    printf("\nFile %s : \n", pathname);
    printf("Size %ld bytes\n" , statbuf.st_size);
    printf("User-id %d, Group-id %d\n\n", statbuf.st_uid , statbuf.st_gid);
    printf("Permissions: %s\n" , descript);
    printf("Permissions: %#o\n" , statbuf.st_mode);

    return 0;
}

int main(int argc , char ** argv)
{
    if(argc != 2)
    {
        fprintf(stderr , "Need File Name\n");
    }

    filedata(argv[1]);

    return 0;
}