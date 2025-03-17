#include <stdio.h>
int main(){
    int num;
    scanf("%d",&num);
    int arr[num][num];
    
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(int i = 0; i < num*num; i++) {
        for(int j = 0; j < num*num-1; j++) {
            int row = j / num; //0 0 0 1 1 1 2 2
            int col = j % num; // 0 1 2 0 1 2 0 1 
            int nextRow = (j+1) / num; // 0 0 1 1 1 2 2 2 
            int nextCol = (j+1) % num; // 1 2 0 1 2 0 1 2
            if(arr[row][col] > arr[nextRow][nextCol]) {
                int temp = arr[row][col];
                arr[row][col] = arr[nextRow][nextCol];
                arr[nextRow][nextCol] = temp;
            }
        }
    }

    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    


    return 0;
}