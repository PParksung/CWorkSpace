#include <stdio.h>
int main(){
    int x,y,n;
    scanf("%d %d", &x,&y);
    scanf("%d", &n);
    int arr[y][x];
    
    int i,j;
    for(i=0; i<y;i++){
        for(j=0; j<x; j++){
            scanf(" %d", &arr[i][j]);
        }
    }
    
    for(i=0; i<y;i++){
        for(int j=0; j<x;j++){
            if(arr[i][j]==n){
                printf("%d %d", i, j);
            }
        }
    }
    
    return 0;
}
