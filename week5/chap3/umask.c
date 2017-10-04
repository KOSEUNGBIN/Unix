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

    /* umask를 0으로 설정*/
    if((oldu = umask(0)) == -1)
    {
        perror("Error : saving old mask\n");
        return -1;
    }

    /* 파일 생성 */
    if((filedes = open(pathname , O_WRONLY | O_CREAT | O_EXCL , mode)) == -1)
    {
        perror("Error : opening file\n");
    }

    /* umask 복원 */
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