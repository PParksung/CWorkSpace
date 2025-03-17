#include <stdio.h>
void changeValueIndex(int **a, int index, int newValue){
    *(*a+index) = newValue;
}

int main(){
    int num;
    scanf("%d", &num);
    int arr[num];
    int * ptr = arr;
    int **pptr = &ptr;
    for(int i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
    
    int index;
    int newValue;
    scanf("%d %d", &index, &newValue);
    changeValueIndex(pptr, index, newValue);

     for(int i=0; i<num; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}