#include <stdio.h>
int main(){
int arr[] = {10, 20, 30};
int * p = arr;//1000
int * q = p + 1;//1004
printf("%p", p);//1000
printf("\n");
printf("%p", q-1);//1000
printf("\n");
printf("%p", arr);//1000
printf("\n");
printf("%p", &arr[0]+1);//1004
printf("\n");
printf("%d", *(q-1));//10
printf("\n");
printf("%d", p[1]);//20
printf("\n");
printf("%d", arr[1]);//20
printf("\n");
printf("%d", *(arr+1));//20
}