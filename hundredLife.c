#include <stdio.h>
#include <string.h>
//letter-'a'+1
int calc(char arr[]){
    int result;
    result = arr[0]-'a'+1;
    return result;
}
int Process(char arr1[], char arr2[]){
    int sum1=0;
    int sum2=0;
    for(int i=0;i<strlen(arr1);i++){
        sum1 += calc(&arr1[i]);
    }
    for(int i=0;i<strlen(arr2);i++){
        sum2 += calc(&arr2[i]);
    }
    if(sum1>=sum2){
        return 1;
    }
    else{
        return 2;
    }
}
int main(){
    char arr1[20];
    scanf("%s", arr1);
    char arr2[20];
    scanf("%s", arr2);
    
    int mode = Process(arr1, arr2);
    if(mode==1){
        printf("%s", arr1);
    }
    else{
        printf("%s", arr2);
    }
    return 0;   
}