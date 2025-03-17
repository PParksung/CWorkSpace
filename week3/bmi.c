#include <stdio.h>
int BMI(float f){
    if(f<20){
        return 1;
    }
    else if(20<=f && f<=24){
        return 2;
    }
    else{
        return 0;
    }
}

int main(){

    int judge;
    float bmi;
    scanf("%f", &bmi);
    judge = BMI(bmi);

    if(judge==1){
        printf("low");
    }//비만지수가 낮다고 판단
    else if(judge==2){
    printf("normal");
    } //비만지수가 정상이라고 판단
    else{
        printf("warning");
    } //비만지수가 높다고 판단
}