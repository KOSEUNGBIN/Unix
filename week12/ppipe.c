//
// Created by 고승빈 on 2017. 11. 15..
//

#include <stdio.h>
#define BUFSIZE 512

int main()
{
    FILE * pipe;
    char buffer[BUFSIZE];
    pipe    = popen("ls -l" , "r");
    if(pipe == NULL){
        perror("popen()");
        return -1;
    }

    while(fgets(buffer, BUFSIZE, pipe))
    {
        printf("%s", buffer);
    }

    pclose(pipe);
    return 0;
}