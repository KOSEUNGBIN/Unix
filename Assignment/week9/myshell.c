//
// Created by 고승빈 on 2017. 10. 28..
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_CMD_ARG 10

const char *prompt = "myshell> ";
char* cmdVector[MAX_CMD_ARG];
char  cmdline[BUFSIZ];

void fatal(char *str);
int cmdlineTokenizer(char *cmdline, const char *delimiters, char** cmdVector, int MAX_LIST);

int main(int argc , char ** argv)
{
    pid_t pid;
    int status;
    int cmdArgCnt;
    int isBackgroud;

    while(1)
    {
        memset(cmdVector , 0x00 , sizeof(char *) * MAX_CMD_ARG);

        fputs(prompt , stdout);
        fgets(cmdline , BUFSIZ , stdin);

        cmdline[ strlen(cmdline) -1] = '\0';

        // 입력된 command line 을 잘라서 cmdVector에 삽입
        if((cmdArgCnt = cmdlineTokenizer(cmdline , " \t" , cmdVector , MAX_CMD_ARG)) == -1)
        {
            fatal("arguments error");
            continue;
        }

        // 현재 프로세스에서 실행해야 하는 명령어
        if(strcmp(cmdVector[0] , "cd") == 0){
            chdir(cmdVector[1]);
            continue;
        }
        else if(strcmp(cmdVector[0] , "exit") == 0)
        {
            break;
        }

        // 백그라운드 명령어가 붙어있는 지 확인
        isBackgroud  = (strcmp(cmdVector[cmdArgCnt-1] , "&") == 0 ? 1 : 0);

        // 자식프로세스 생성
        pid = fork();

        if(pid == -1)
        {
            // 에러
            fatal("fork error");
        }
        else if(pid == 0)
        {
            // 자식 프로세스

            // 백그라운드인 경우 &를 제거
            if(isBackgroud == 1)
            {
                cmdVector[cmdArgCnt-1] = NULL;
            }

            // 실행 프로그램 변경
            execvp(cmdVector[0] , cmdVector);

            // 에러
            fatal("could not call execvp error");
        }
        else
        {
            // 부모 프로세스

            // 포그라운드인 경우
           if(isBackgroud == 0)
           {
               // 자식 프로세스를 대기
               waitpid(pid , &status , 0);
           }
           else
           {
               // 자식 프로세스를 고아 프로세스로 만들어서 백그라운드로 실행
               sleep(1);
           }
        }
    }

    return 0;
}

// command line 의 arguments 잘라서 cmdVector에 삽입
int cmdlineTokenizer(char *cmdline, const char *delimiters, char** cmdVector, int MAX_LIST)
{
    int numtokens = 0;
    char *snew = NULL;

    if( (cmdline==NULL) || (delimiters==NULL) ) return -1;

    snew = cmdline + strspn(cmdline, delimiters);
    if( (cmdVector[numtokens]=strtok(snew, delimiters)) == NULL )
        return numtokens;

    numtokens = 1;

    while(1){
        if( (cmdVector[numtokens]=strtok(NULL, delimiters)) == NULL)
            break;
        if(numtokens == (MAX_LIST-1)) return -1;
        numtokens++;
    }
    return numtokens;
}

// 에러 처리
void fatal(char *str){
    perror(str);
    exit(1);
}