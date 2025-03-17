#include <stdio.h>
#define ARRAY_SIZE 3

void elementwiseSum(int (*arr1)[ARRAY_SIZE], int (*arr2)[ARRAY_SIZE]){
    int sum[ARRAY_SIZE][ARRAY_SIZE];
    for(int i=0; i<ARRAY_SIZE; i++){
        for(int j=0; j<ARRAY_SIZE; j++){
            sum[i][j] = arr1[i][j]+arr2[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr1 [ARRAY_SIZE][ARRAY_SIZE];
    int arr2 [ARRAY_SIZE][ARRAY_SIZE];

    for(int i = 0; i < ARRAY_SIZE; i++){
        for(int j = 0; j < ARRAY_SIZE; j++){
            scanf("%d", &arr1[i][j]);
        }
    }    

   for(int i = 0; i < ARRAY_SIZE; i++){
        for(int j = 0; j < ARRAY_SIZE; j++){
            scanf("%d", &arr2[i][j]);
        }
    }    
    elementwiseSum(arr1, arr2);
    
    return 0;
}