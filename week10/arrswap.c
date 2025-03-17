#include <stdio.h>
#define ARRAY_SIZE 5
void swap(int (*arr)[ARRAY_SIZE], int p1, int p2) {
    int i1 = p1/5;
    int i2 = p1%5;
    int i3 = p2/5;
    int i4 = p2%5;
    int temp = arr[i1][i2];
    arr[i1][i2] = arr[i3][i4];
    arr[i3][i4] = temp;
}
int main(){
    int arr[ARRAY_SIZE][ARRAY_SIZE];

    int p1;
    int p2;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j=0; j < ARRAY_SIZE; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    scanf("%d %d", &p1, &p2);
	
    swap(arr, p1, p2);

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        for (int j=0; j < ARRAY_SIZE; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}