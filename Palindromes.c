#include <stdio.h>

int pal(char arr[], int length);

int main(){
    int n;
    scanf("%d",&n);//실행할 개수

    int results[n];

    for(int i=0; i<n; i++){
        int length;
        scanf("%d", &length);//문자 길이
        
        char arr[length];
        scanf("%s", arr);

       if (pal(arr, length)) {
            results[i] = 1; 
        } else {
            results[i] = 0; 
        }
    }

    for(int i=0; i<n;i++){
        if(results[i]==1){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}

int pal(char arr[], int length){
    int left = 0;
    int right = length -1;

    while(left<right){
        if(arr[left]!= arr[right])
            return 0;
        left++;
        right--;
        
        }
    return 1;
}
