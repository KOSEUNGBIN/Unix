//
// Created by 고승빈 on 2017. 10. 4..
//

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc , char ** argv)
{
    pid_t pid;
    int status;

    printf("Just one process so far\n");
    printf("Calling fork ....\n");

    pid = fork();

    if(pid == 0)
    {
        /* 자식 프로세스일 경우 */
        printf("I'm the child\n");
        exit(100);
    }
    else if(pid > 0)
    {
        /* 부모 프로세스일 경우 */
        wait(&status);
        printf("I'm the parent, child has pid %d , status %d\n" , pid , status);
    }
    else
    {
        /* 예외 발생시 */
        printf("Fork returned error code, no child\n");
    }

    return 0;
}