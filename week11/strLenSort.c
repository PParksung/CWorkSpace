#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortStrings(char **arr, int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (strlen(arr[j]) < strlen(arr[j+1])) {
                char *temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    char **strings = (char **)malloc(N * sizeof(char *));
    
    for (int i = 0; i < N; i++) {
        strings[i] = (char *)malloc(101 * sizeof(char));
        scanf(" %[^\n]s", strings[i]);
    }
    
    sortStrings(strings, N);
    
    for (int i = 0; i < N; i++) {
        printf("%s\n", strings[i]);
        free(strings[i]);
    }
    free(strings);
    
    return 0;
}
