#include <stdio.h>
#include <string.h>
int main(){
    char word [4] = "abc";
    strcpy(word, "ab");
    printf("%s", word);
}