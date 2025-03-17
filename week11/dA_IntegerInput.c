#include <stdio.h>
#include <stdlib.h>

int main() {
    int totalSize = 5;
    int *array = (int *)malloc(totalSize * sizeof(int));
    int input, count = 0;

    while (1) {
        scanf("%d", &input);

        if (count == totalSize) {
            totalSize += 3;
            int *temp = (int *)realloc(array, totalSize * sizeof(int));
            array = temp;
        }

        array[count++] = input;

        if (input == -1) break; 
    }
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}
