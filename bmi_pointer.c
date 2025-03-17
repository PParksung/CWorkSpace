#include <stdio.h>
void BMI(float *f){
    for(int i=0; i<3; i++){
        if(f[i]<20){
            printf("low ");
        }
        if(f[i]>=20 && f[i]<=24){
            printf("normal ");
        }
        if(f[i]>24){
            printf("warning ");
        }
    }
    printf("\n");
}
int main(){
    float bmi[3];
    scanf("%f %f %f",&bmi[0],&bmi[1],&bmi[2]);
    BMI(bmi);
    return 0;
}