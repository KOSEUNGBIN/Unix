//
// Created by 고승빈 on 2017. 9. 27..
//

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int specialcreate (const char *pathname , mode_t mode)
{
    mode_t oldu;
    int filedes;

    if((oldu = umask(0)) == -1)
    {
        perror("Error : saving old mask\n");
        return -1;
    }

    printf("%#o\n" , oldu);
    printf("%d\n" , oldu);


    if((filedes = open(pathname , O_WRONLY | O_CREAT | O_EXCL , mode)) == -1)
    {
        perror("Error : opening file\n");
    }

    if(umask(oldu) == -1)
    {
        perror("restoring old mask\n");
    }

    return filedes;
}

int main(int argc , char ** argv)
{

    printf("Opened : %d\n" , specialcreate("modeFile" , 0111));

    return 0;

}