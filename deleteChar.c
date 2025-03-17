#include <stdio.h>
int main(){
    char sentence [80];
    char delete;  
    scanf("%[^\n]s", sentence);
    scanf(" %c", &delete);
    char * ptr = sentence;
    char after_sentence[80]={'0'};

    int i;
    int index=0;
    int len = sizeof(sentence)/sizeof(char);
    for(i=0; i<len; i++){
        if(delete != sentence[i]){
            after_sentence[index] = sentence[i];
            index++;
        }
    }
    printf("%s", after_sentence);
}
