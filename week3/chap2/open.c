//
// Created by 고승빈 on 2017. 10. 27..
//

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int main()
{

    if(-1 == open("tmp" , O_WRONLY | O_CREAT, 999))
    {
        perror("erro");
    }

    printf("%o\n" , umask(1));
    printf("%o\n" , 999);

    return 0;
}

