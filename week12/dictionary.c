#include <stdio.h>
#include <string.h>

typedef struct {
    char key[11];
    char value[11];
} dict;

int main() {
    int n;
    scanf("%d", &n);
    
    dict dictionary[n];
    
    for(int i = 0; i < n; i++) {
        scanf("%s", dictionary[i].key);
        scanf("%s", dictionary[i].value);
    }
    
    char inputKey[11];
    while(1) {
        scanf("%s", inputKey);
        
        if(strcmp(inputKey, "exit") == 0) {
            break;
        }
        
        int found = 0;
        
        for(int i = 0; i < n; i++) {
            if(strcmp(dictionary[i].key, inputKey) == 0) {
                printf("%s\n", dictionary[i].value);
                found = 1;
                break;
            }
        }
        
        if(found == 0) {
            printf("No match key in dictionary\n");
        }
    }
    
    return 0;
}