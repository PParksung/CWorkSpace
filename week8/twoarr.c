#include <stdio.h>
int main(){
    int x , y;
    scanf("%d %d", &x, &y);
    int arr[y][x];
    int i,j;
    for(i=0; i<y; i++){
        for(j=0; j<x; j++){
            scanf("  %d", &arr[i][j]);
        }
    }

    int sum = 0;
    for(i=0; i<y; i++){
        for(j=0; j<x; j++){
            sum += (int)arr[i][j];
        }
    }
    printf("%d", sum/(x*y));
    return 0;
}
/*
3 4
83 86 77 
15 93 35 
86 92 49 
21 62 27 
*/