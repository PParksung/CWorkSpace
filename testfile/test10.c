#include <stdio.h>
int main(){
    int sum=0;
    for(int i=1;i<=10;i++){
        if(i%3==0){
            continue;
        }
        sum+=i;
    }
    printf("%d",sum);
}