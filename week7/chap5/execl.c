//
// Created by 고승빈 on 2017. 10. 10..
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("executing ls\n");

    execl("/bin/ls" , "ls" , "-l" , (char *) 0);

    perror("execl failed to run ls");
    exit(1);
}
