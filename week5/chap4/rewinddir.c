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

    /* Directory open */
    if((dp = opendir(name)) == NULL)
    {
        return -1;
    }

    /* loop 를 돌며 directory entry를 리턴*/
    while((d = readdir(dp)) != NULL)
    {
        /* i node 가 유효한지 확인
         * i node == 0 이면 directory entry 의 빈 항을 의미*/
        if(d->d_ino != 0)
        {
            printf("%s \n" , d->d_name);
        }
    }

    /* Directory pointer의 시작 주소로 이동 */
    rewinddir(dp);

    while((d = readdir(dp)) != NULL)
    {
        if(d->d_ino != 0)
        {
            printf("%s \n" , d->d_name);
        }
    }

    closedir(dp);

    return 0;
}

int main(int argc , char ** argv)
{

    if(argc != 2)
    {
        fprintf(stderr , "Usage : ./rewinddir < directory name > \n");
        exit(1);
    }

    my_double_ls(argv[1]);

    return 0;
}