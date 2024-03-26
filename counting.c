#include <stdio.h>
#include <string.h>
void Counting(char arr[]) {
    int count[10] = {0}; 

    for (int i = 0; i<strlen(arr); i++) {
        int digit = arr[i] - '0';
        count[digit]++;
    }


    for (int i = 0; i < 10; i++) {
        printf("%d ", count[i]);
    }
}

int main() {
    char arr[1000];

    scanf("%s", arr);

    Counting(arr);

    return 0;
}