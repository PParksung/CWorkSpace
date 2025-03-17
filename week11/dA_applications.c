#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int** arr;
    int x, y;
    int sum = 0, count = 0, average = 0;

    scanf("%d %d", &x, &y);

    arr = (int**)malloc(y * sizeof(int*));
    for(int i = 0; i < y; i++) {
        arr[i] = (int*)malloc(x * sizeof(int));
    }

    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
            count++;
        }
    }

    average = sum / count;

    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            if (arr[i][j] <= average) {
                arr[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < y; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
