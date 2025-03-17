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

    for(int i=num*num-1; i>=0 ; i--){
        printf("%d ", arr[i/num][i%num]);
    }   
    return 0;
}