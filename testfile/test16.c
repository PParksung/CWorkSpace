#include <stdio.h>
int main(){
    char *p;
    /*
    char p[10];
    char **p;
    char *p[10];
    char (*p)[10];
    char **p[10];
    char ***p;
    char (**p)[10];
    */
    char *** tptr;
    tptr = &p;
    printf("%p", p);
}