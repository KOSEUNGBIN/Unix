//
// Created by 고승빈 on 2017. 9. 30..
//

#include <stdio.h>
#include <unistd.h>
#define  VERYBIG    200

void my_pwd (void);

int main()
{
    my_pwd();
}

void my_pwd(void)
{
    char dirname[VERYBIG];

    if(getcwd(dirname , VERYBIG) == NULL)
    {
        perror("getcwd error");
    }
    else
    {
        printf("%s\n", dirname);
    }
}