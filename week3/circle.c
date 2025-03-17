#include <stdio.h>
double mian(int num){
    return 2*num*3.141592;
}
double dul(int num){
    return num*num*3.141592;
}
int main(){
    int r;
    scanf("%d", &r);
    printf("%.3lf %.3lf", mian(r), dul(r));
}
