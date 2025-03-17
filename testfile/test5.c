#include <stdio.h>
int main(){
    char a[] = "Hello";
    char * p[] = {a, a+1, a+2, a+3, a+4};
    printf("%s %c \n", a, *a);//hello h
    printf("%s %c \n", a+1, *(a+1));//ello e
    printf("%p %p %s \n", p, *p, *p);//1000 1024 hello   
    printf("%s %s %s %s\n", *p,*(p+1),*(p+2),*(p+3));//hello ello ello llo
}