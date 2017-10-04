//
// Created by 고승빈 on 2017. 10. 1..
//

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc , char ** argv)
{
    char confirm;
    if(argc != 2)
    {
        fprintf(stderr , "Usage : ./3-8 removed file\n");
        exit(1);
    }

    if(access(argv[1] , W_OK) == -1)
    {
        fprintf(stderr , "You do not have write permission.\n Do I want to continue? (y or n)");
        scanf("%c", &confirm);

        if(confirm == 'y' || confirm == 'Y')
        {
            unlink(argv[1]);
        }
        else
        {
            exit(1);
        }
    }
    else
    {
        unlink(argv[1]);
    }




    return 0;
}