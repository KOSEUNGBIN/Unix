//
// Created by 고승빈 on 2017. 11. 15..
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/errno.h>

#define FIFO "/tmp/fifo"
#define  BUFSIZE    512

int main()
{
    int fd;
    int res;
    char buffer[BUFSIZE];

    while((fd = open(FIFO, O_RDWR | O_NONBLOCK)) < 0)
    {
        if(errno != ENOENT) return -1;

        printf("Pi[e is not readt, waiting 1 sec.\n");
        sleep(1);
    }

    while(1)
    {
        res = read(fd, buffer, BUFSIZE);

        if(res < 0)
        {
            if(errno != EAGAIN) break;

            sleep(1);
            continue;
        }

        printf(">> %s", buffer);
    }

    close(fd);
    return 0;
}