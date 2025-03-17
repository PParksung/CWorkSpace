#include <stdio.h>
int main(){
    
    int n,m;
    scanf("%d %d", &n, &m);
    
    char arr[100]={};
    scanf("%s", arr);

    int group = n/m; //4 or 2

    char *ptr= arr;
    
    for(int i=0; i< m; i++){//m번 반복
        for(int j=(i+1)*group-1; j>=i*group; j--){
            printf("%c", *(ptr+j));
        }
    }
    printf("\n");

    return 0;
}