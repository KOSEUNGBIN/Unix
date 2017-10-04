//
// Created by 고승빈 on 2017. 10. 1..
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


#define FILESIZE    10
#define BUFSIZE     2048

int main(int argc , char ** argv)
{
    struct stat buf;
    time_t updateFileTime[FILESIZE];
    int i , rcount;
    char buffer[BUFSIZE];
    FILE * fp;


    if(argc < 2)
    {
        fprintf(stderr, "Usage : ./3-10 file1 file2 ...\n");
        exit(1);
    }

    if(--argc > FILESIZE)
    {
        fprintf(stderr, "Too many files..\n");
        exit(1);
    }

    /*
     * initialize updateFileTime array
     * */
    for(i = 1 ; i <= argc ; ++i)
    {
        if(stat(argv[i] , &buf) == -1)
        {
            fprintf(stderr , "Error : couldn't stat %s\n", argv[i]);
        }
        else
        {
            updateFileTime[i - 1] = buf.st_mtime;
        }
    }

    while(1)
    {
        for( i = 1 ; i <= argc ; ++i)
        {
            /*
             * file에 수정이 일어났을 경우
             *
             * */
            if(stat(argv[i] , &buf) != -1 && updateFileTime[i - 1] != buf.st_mtime)
            {
                if((fp = fopen(argv[i] , "r")) != NULL)
                {
                    while(!feof(fp))
                    {
                        rcount = fread((void *) buffer , 1 , BUFSIZE , fp);
                        fwrite(buffer , 1 , rcount , stdout);
                    }
                    fclose(fp);
                }

                updateFileTime[i - 1] = buf.st_mtime;
            }
        }
    }

    return 0;
}