#include <stdio.h>
int main(){
    int n;
    int count;
    int line=0;
    scanf("%d",&n);
    if(n>=2&&n<=1000){
      for(int i=2; i<=n; i++){
        count = 0;
        for(int j=2; j<=i; j++){
            if(i%j==0){
                count++;
            }
        }
        if(count ==1)
        {
            printf("%d ", i);
            line++;
            if(line%10==0){
                printf("\n");
            }
        }
      }
    }

    return 0;
}