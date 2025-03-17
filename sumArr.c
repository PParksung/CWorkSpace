#include <stdio.h>
int sumarr(int *p, int num);
int main(){
    int i;
    int arr[5]={0};
    int *p=arr;
    int num;
    int result;
    for(i=0; i<5; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &num);

    result = sumarr(arr, num);
    printf("%d", result);
    
    return 0;
}
int sumarr(int *p, int num){
    int i;
    int sum=0;
    for(i =0; i<5; i++){
        sum+=p[i]+num;
    }
    return sum;
}
