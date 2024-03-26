#include <stdio.h>
int i=0;
void func1() {
    int i=100;
    i++;
    printf("(1) : %d\n", i);
}

void func2() {
    printf("(2) : %d\n", i);
    i++;
    printf("(3) : %d\n", i);
}

int main(){

    func1();
    printf("(4) : %d\n",i);
    func2();
    printf("(5) : %d\n", i);
    return 0;
}