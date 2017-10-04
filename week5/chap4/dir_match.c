//
// Created by 고승빈 on 2017. 10. 4..
//

#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int match(const char * s1, const char * s2);

char * find_entry(char *dirname , char *suffix , int cont);

int main(int argc , char ** argv)
{
    char * searchFile;
    if(argc != 3)
    {
        fprintf(stderr , "Usage : ./dir_match <base directory> <suffix>\n");
        exit(1);
    }

    if((searchFile = find_entry(argv[1] , argv[2] , 0)) == NULL)
    {
        fprintf(stderr , "Not Found <suffix : %s> ,\n" , argv[2]);
        exit(1);
    }

    printf("%s\n" , searchFile);
}

int match(const char * s1, const char * s2)
{
    int diff = strlen(s1) - strlen(s2);

    if(strlen(s1) > strlen(s2)) return (strcmp(&s1[diff] , s2) == 0);
    else                        return 0;
}

char * find_entry(char *dirname , char *suffix , int cont)
{
    static DIR * dp = NULL;
    struct dirent *de;


    if(dp == NULL || cont == 0){
        if(dp != NULL)  closedir(dp);

        if((dp = opendir(dirname)) == NULL) return NULL;
    }

    while((de = readdir(dp)) != NULL)
    {
        if(de->d_ino == 0) continue;

        if(match(de->d_name , suffix))  return de->d_name;
    }

    closedir(dp);
    dp = NULL;
    return NULL;
}