#include <stdio.h>
int fib(int num){
    if(num ==1){
        return 1;
    }
    else if(num ==2){
        return 1;
    }
    else{
        return fib(num-1)+fib(num-2);
    }

}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d",fib(n));
}