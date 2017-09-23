//
// Created by 고승빈 on 2017. 9. 20..
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFSIZE 4096

int main()
{
    char buffer[BUFFSIZE];
    int filedes;
    int line = 1 , word = 0 , isWord = 0;
    int index , ascii;
    ssize_t nread;

    if((filedes = open("inputfile" , O_RDONLY)) == -1)
    {
        printf("error in inputCount\n");
        exit(1);
    }

    while((nread = read(filedes , buffer , BUFFSIZE)) > 0)
    {
        isWord = 0;
        for(index = 0; index < nread ; ++index)
        {
            ascii = (int)buffer[index];

            if(ascii == 10) ++line;

            if(isWord == 1)
            {
                if(ascii == 9 || ascii == 10 || ascii == 32)
                {
                    ++word; isWord = 0;
                }
            }
            else
            {
                if(!(ascii == 9 || ascii == 10 || ascii == 32)) isWord = 1;
            }
        }
    }

    printf("word : %d , line : %d\n",word , line);
    exit(0);

}