#include <stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    
    int i;
    int arr[50] = {0};
    for(i=0; i<num; i++){
        scanf("%d", &arr[i]);
    }
    int input=0;
    while(1){
        scanf("%d", &input);
        if(input ==-1){
            break;
        }
        else{
            if(input <= num && input >=1){
            int result = arr[input-1];
            printf("%d\n", result);
            }
        }
        
    }
    printf("bye");
    return 0;
}