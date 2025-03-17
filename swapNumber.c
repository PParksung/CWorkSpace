#include <stdio.h>
void swap(int *a, int *b);
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    swap(&n,&m);
    printf("%d %d", n, m);
    return 0;
}
void swap(int* a,int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
