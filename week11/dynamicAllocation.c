#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int** arr;
    int x, y;
    int count = 1;

    scanf("%d %d", &x, &y);

    arr = (int**)malloc(y * sizeof(int*));
    for (int i = 0; i < y; i++) {
        arr[i] = (int*)malloc(x * sizeof(int));
    }
    

    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            arr[i][j] = count++;
        }
    }
    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < y; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
