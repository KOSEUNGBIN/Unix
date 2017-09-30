//
// Created by 고승빈 on 2017. 9. 30..
//

#include <unistd.h>
#include <stdio.h>

typedef struct{
    int val;
    char *name;
} Table;

int main()
{
    Table * tb;
    static Table options[] = {
            { _PC_LINK_MAX , "Maximum number of links" },
            { _PC_NAME_MAX , "Maximum length of a filename"},
            { _PC_PATH_MAX , "Maximum length of a pathname"}
    };

    for(tb = options; tb->name != NULL ; tb++)
    {
        printf("%-28.28s\t%ld\n" , tb->name , pathconf("/tmp" , tb->val));
    }
}