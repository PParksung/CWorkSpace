#include <stdio.h>
#include <string.h>
int main() {
    char input [100]; 
    scanf("%s", input);
    int length = strlen(input);
    int temp;
    for(int i=1; i<length; i++){
        //length-1만큼 반복
        for(int j=0; j<length-i; j++){
            if(input[j]>input[j+1]){
                temp = input[j];
                input [j]=input[j+1];
                input[j+1] = temp;
            }
        }
        
    }
    
}