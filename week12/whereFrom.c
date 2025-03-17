#include <stdio.h>
#include <string.h>
struct student
{
    char name[20];
    char region[20];
};
int main(){
    struct student s[10];
    for(int i=0; i<10; i++){
        scanf("%s", s[i].name);
        scanf("%s", s[i].region);
    }

    char correct_name[20];
    scanf("%s", correct_name);

    for(int i=0; i<10; i++){
        if(strcmp(correct_name, s[i].name)==0){
            printf("%s\n", s[i].region);
            break;
        }
    }

    return 0;
}