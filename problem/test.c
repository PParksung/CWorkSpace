#include <stdlib.h> 
#include <stdio.h> 
#include <signal.h>
#include <unistd.h>  // 추가: sleep() 함수가 선언된 헤더 파일

void handler(int sig) 
{
    printf("You think hitting ctrl-c will stop the bomb?\n");
    sleep(2);  // sleep 함수는 <unistd.h>에 정의되어 있음
    printf("Well...");
    fflush(stdout);
    sleep(1);
    printf("OK\n");
    exit(0);
}

int main() 
{    
    /* installs ctl-c handler */
    signal(SIGINT, handler); 
    
    while(1) { }
}
