#include <stdio.h>
int main(){
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int plus = num1+num2;
    int sub = num1-num2;
    int mul = num1*num2;
    int div = num1/num2;
    printf("%d %d %d %d\n", plus,sub,mul,div);
}