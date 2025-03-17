#include <stdio.h>

int main(){
    int arr[5];
    int i, f;
    for(i = 0; i < 5; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &f);

    // 0 1 2 3 4
    int sum = 0;
    int *ptr = arr;
    for(i = 0; i < 5; i++, ptr++){
        *ptr += f;
        sum += *ptr;
    }
    printf("%d\n", sum);

    return 0;
}