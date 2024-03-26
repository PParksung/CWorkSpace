#include <stdio.h>
#include <math.h>
int main(void){
   
    int c,t;
    scanf("%d %d", &c,&t);
    //이동시간이 10분 이상
    //가는동안 부피 2배
    //가는동안 짐칸 초과
    // 이경우엔 can not
    float x =(pow( 2, (t/10)));
    if(x>c){
        printf("Can not\n");
    }
    else{
        printf("%.0f\n", c/x);
    }

    return 0;
}
