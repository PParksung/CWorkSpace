#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    char input[n][80];
    int i,j;
    for(i=0; i<n; i++){
        scanf("%s", input[i]);
    }

    int sum=0;
    for(i=0; i<n; i++){
        for(j=0;j<80;j++){
            if(input[i][j]=='\0'){
                break;
            }
            sum++;
        }
    }
    printf("%d", sum);
    return 0;
}