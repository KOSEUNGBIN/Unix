//
// Created by 고승빈 on 2017. 9. 30..
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc , char ** argv)
{
    char * accessCheckFile = "accessCheckFile";

    if(access(accessCheckFile , F_OK) == -1)        perror("Not Found File");
    else if(access(accessCheckFile , R_OK) == -1)   perror("Dosen't Read File");
    else if(access(accessCheckFile , W_OK) == -1)   perror("Dosen't Write File");
    else if(access(accessCheckFile , X_OK) == -1)   perror("Dosen't Execute File");
    else                                            printf("Hase All Permission About %s File\n" , accessCheckFile);

    exit(0);
}

