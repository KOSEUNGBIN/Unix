//
// Created by 고승빈 on 2017. 11. 15..
//

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/errno.h>

#define FIFO "/tmp/fifo"
#define BUFSIZE 512
#define MODE    0600

int main()
{
    int fd = -1;
    char buffer[BUFSIZE];
    if(-1 == mkfifo(FIFO,MODE)) return -1;

    while((fd = open(FIFO, O_WRONLY | O_NONBLOCK)) < 0)
    {
        if(errno != ENXIO)  return -2;

        printf("No process is reading, waiting 1 sec.\n");
        sleep(1);
    }
    while(1)
    {
        printf("> ");
        if(fgets(buffer, BUFSIZE - 1, stdin) <= 0)
        {
            break;
        }
        write(fd, buffer, BUFSIZE);
    }
    close(fd);
    unlink(FIFO);

}
