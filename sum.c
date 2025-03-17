#include <stdio.h>
#include <stdlib.h>
int main(){
int n;
int index_i;
int index_j;
int result=0;

scanf("%d", &n);
int * arr=malloc(sizeof(int)*n);
for(int i=0; i<n; i++){//배열에 입력값 넣어줌
    scanf("%d", &arr[i]);
}

scanf("%d %d", &index_i, &index_j);//인덱스 i,j입력

for(int i=index_i; i<index_j+1; i++){
    result += arr[i]; // i,j사이 인덱스 값 더한 값 출력
}


printf("%d\n", result);
return 0;

}
