#include <stdio.h>
int a[] = {0,1,2,3,4};
int main(){
    int i, *p;

    for(i=0; i<=4; i++) printf("%d ", a[i]);//0 1 2 3 4
    printf("\n");
    for(p=&a[0]; p<=&a[4]; p++) printf("%d ", *p);//0 1 2 3 4 
    printf("\n");
    for(p=&a[0], i=1; i<=5; i++) printf("%d ", p[i]);//1 2 3 4 0
    printf("\n");
    for(p=a, i=0; p+i<=a+4;p++,i++) {printf("%d ", *(p+i));}// 0 2 4
    printf("\n");
    int *q=a; for(p=a+4;p>=q;q++,p--) printf("%d ", *p);//4 3 2
    printf("\n");
    for(p=a+4, i=0; i<=4;i++) {printf("%d ", p[-i]);}// 4 3 2 1 0
    printf("\n");
    for(p=a+4;p>=a;p--) printf("%d ", a[p-a]);// 4 3 2 1 0

}