#include <stdio.h>
#define ARRAY_SIZE 5

int foo(int (*arr)[5], int x){
    int result = 0;
    for(int i=0; i<x; i++){
        int min = arr[i][0];
        for(int j=0; j<ARRAY_SIZE; j++){
            if(arr[i][j]<min){
                min = arr[i][j];
            }
        }
        result+=min;
    }
    return result;
}

int main() {
    int x;
    scanf("%d", &x);
    int arr[x][ARRAY_SIZE];

    for(int i = 0; i < x; i++){
        for(int j = 0; j < ARRAY_SIZE; j++){
            scanf("%d", &arr[i][j]);
        }
    }    

    int result = foo(arr,x);
    printf("%d\n",result);
    
    return 0;
}