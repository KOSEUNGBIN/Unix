//
// Created by 고승빈 on 2017. 10. 26..
//

#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("%d\n" , dup2(1 , 2));
    return 0;
}