#include <stdio.h>
int main(void){
    int c, t;
    scanf("%d %d", &c, &t);
    int r = pow(2,t/10);
    int result = c/r;
    if(r>c){
        printf("Can not");
    }
    else{
        printf("%d", result);
    }
    return 0;
}
