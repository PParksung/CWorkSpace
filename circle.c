#include <stdio.h>
double circle_area(int r){
    //3.141592*r*r
    return 3.141592*r*r;
}

double circle_round(int r){
    //2*3.141592*r
    return 2*3.141592*r;
}

int main(){
    int num;
    double result1;
    double result2;
    scanf("%d", &num);
    result1 = circle_area(num);
    result2 = circle_round(num);
    printf("%.3lf %.3lf\n", result2, result1);
}