#include <stdio.h>
void f(const char * a) {
    printf("f : %c\n", *a);
    a = "hi";
    printf("change f : %c\n", *a);
}
void g(char * const a) {
    printf("g : %c\n", *a);
    *a = "hi";
    
    printf("change g : %c\n", *a);
}
int main(){
    
    char s1[] = "Hello";
    char * s2 = "Hello";
    g(s1);
    f(s2);

}