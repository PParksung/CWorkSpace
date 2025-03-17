#include <stdio.h>

void swap(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int arr1[5];
    int arr2[5];

    int* ptr1 = arr1;
    int* ptr2 = arr2;
    int **pptr1 = &ptr1;
    int **pptr2 = &ptr2;
    
    for(int i = 0; i < 5; i++) {
        scanf(" %d", &arr1[i]);
    }
    for(int i = 0; i < 5; i++) {
        scanf(" %d", &arr2[i]);
    }

    swap(pptr1, pptr2);

    for(int i = 0; i < 5; i++) {
        printf("%d ", ptr1[i]);
    }
    printf("\n");
    for(int i = 0; i < 5; i++) {
        printf("%d ", ptr2[i]);
    }

    return 0;
}