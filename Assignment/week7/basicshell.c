//
// Created by 고승빈 on 2017. 10. 11..
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#define mode    0755

int main(int argc , char ** argv)
{
    char input[50] , arg[50];
    while(1)
    {
        scanf("%s %s" , input , arg);

        if(strcmp(input , "touch") == 0)
        {
            if(creat(arg , mode) == -1)
            {
                perror("touch create error");
            }
            else
            {
                printf("Create %s File\n", arg);
            }

        }
        else if(strcmp(input , "rm") == 0)
        {
            if(unlink(arg) == -1)
            {
                perror("rm error");
            }
            else
            {
                printf("Remove %s File\n", arg);
            }
        }
        else if(strcmp(input , "mkdir") == 0)
        {
            if(mkdir(arg , mode) == -1)
            {
                perror("rm error");
            }
            else
            {
                printf("Create %s Directory\n", arg);
            }
        }
        else if(strcmp(input , "rmdir") == 0)
        {
            if(rmdir(arg) == -1)
            {
                perror("rm error");
            }
            else
            {
                printf("Remove %s Directory\n", arg);
            }
        }
        else
        {
            break;
        }

    }
}