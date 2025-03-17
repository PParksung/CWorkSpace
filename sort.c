#include <stdio.h>
void sort(int *a, int b){//a가 배열, b가 길이
    int max = a;
    for(int i=0; i<b; i++){//b만큼
        if(max < a){
            
        }
    }
}
int main(){
    int arr[10]={0};
    int i;
    int *p= arr;
    for(i=0; i<10; i++){
        scanf("%d", &arr[i]);
    }
    int len = 10;
    for(i=0; i<9; i++){
        sort(p, len);
        len--;
    }
    for(i=0;i<10;i++){
        printf("%d", arr[i]);
    }
}