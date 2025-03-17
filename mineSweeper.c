#include <stdio.h>
int main(){
    char arr[10] = {'0'};
    int i;
    scanf("%s", arr);
    for(i=0; i<9; i++){
        if(arr[i]=='.'){
            if(arr[i+1]=='*'){
                arr[i]='1';
            }
            else if(arr[i+1]!='*'){
                arr[i]='_';
            }
        }
     }
    for(i=9; i>0;i--){
        if(arr[i]=='1'&& arr[i-1]=='*'){
            arr[i]='2';
        }
        if(arr[i]=='.'){
            if(arr[i-1]=='*'){
            arr[i]='1';
            }
            else if(arr[i-1]!='*'){
                arr[i]='_';
            }
        }
        if(arr[i]=='_'){
            if(arr[i-1]=='*'){
            arr[i]='1';
            }
        }
    }

    
    printf("%s", arr);
    return 0;
}
