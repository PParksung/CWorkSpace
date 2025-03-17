#include <stdio.h>
int main(){
    char arr[100];
    scanf("%s", arr);
    char *ptr= arr;
    int count[26] = {};

    while(*ptr != '\0'){
        count[*ptr-'a']++;
        ptr ++;
    }
    for(int i=0; i<26; i++){
        printf("%d ", count[i]);
    }
    printf("\n");
    
    return 0;
}