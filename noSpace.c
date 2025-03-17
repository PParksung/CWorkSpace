#include <stdio.h>
#include <string.h>
int main(){
int n;
char input[10];
int sum=0;

scanf("%d", &n);

for(int i=0; i<n; i++){
    scanf("%s", input);
    sum += strlen(input);
    
}
printf("%d",sum);

return 0;
}