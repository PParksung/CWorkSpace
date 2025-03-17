#include <stdio.h>

int main(){
    int arr[9] = {0};
    int i;
    int *ptr = arr;
    int len = sizeof(arr)/sizeof(int);
    for(i=0; i<len; i++){
        scanf("%d", &arr[i]);
    }
    int max = ptr[0];
    int min = ptr[0];
    int max_index=1;
    int min_index=1;

    for(i=1; i<len; i++){
        if(max< ptr[i]){
            max = ptr[i];
            max_index = i+1;
        }
        if(min > ptr[i]){
            min = ptr[i];
            min_index = i+1;
        }
    }

    printf("%d\n%d\n%d\n%d",max,max_index, min, min_index);
    return 0;
}
//3 29 38 12 57 74 40 85 61