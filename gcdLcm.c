#include <stdio.h>
void gcdlcm(int n, int m, int*a, int *b){
    if(n>m){
       int temp = n;
       n = m;
       m = temp;
    }
    *a=1;
    int i;
    for(i=2; i<=m; i++){
        if(n%i==0 && m%i==0){
            *a = i;
        }
    }

    *b=n*m/(*a);

}

int main(){
    int n,m,a,b;
    scanf("%d %d", &n,&m);
    gcdlcm(n,m,&a,&b);
    printf("%d %d", a,b);
    return 0;
}