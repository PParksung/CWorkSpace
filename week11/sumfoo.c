#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 5

int foo(int (**arr), int x){
    int result = 0;
    for(int i = 0; i < x; i++){
        int min = arr[i][0];
        for(int j = 1; j < ARRAY_SIZE; j++){
            if(arr[i][j] < min){
                min = arr[i][j];
            }
        }
        result += min;
    }
    return result;
}

int main() {
    int** arr;
    int x;
    int result;
    
    scanf("%d", &x);
    
    arr = (int**)malloc(x * sizeof(int*)); 
    for(int i = 0; i < x; i++){
        arr[i] = (int*)malloc(ARRAY_SIZE * sizeof(int)); 
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < ARRAY_SIZE; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    result = foo(arr, x);
    printf("%d\n", result);
    
    for(int i = 0; i < x; i++){
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}
