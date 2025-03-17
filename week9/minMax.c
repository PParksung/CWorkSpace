#include <stdio.h>
void max_num(int **ptr_max, int num[]);
void min_num(int **ptr_min, int num[]);
int main(){
    int num[5];
    for(int i=0; i<5; i++){
        scanf("%d", &num[i]);
    }
    int max= num[0];
    int *ptr_max =&max;
    int **pptr_max = &ptr_max;

    int min = num[0];
    int *ptr_min = &min;
    int **pptr_min = &ptr_min;
    max_num(pptr_max, num);
    min_num(pptr_min, num);

    printf("%d %d", min, max);
    return 0;
}
void max_num(int **ptr_max, int num[]){
    for (int i=0; i<5; i++){
        if(**ptr_max<num[i]){
            **ptr_max = num[i];
        }
    }
}
void min_num(int **ptr_min, int num[]){
    for (int i=0; i<5; i++){
        if(**ptr_min>num[i]){
            **ptr_min = num[i];
        }
    }
}
