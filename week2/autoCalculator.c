#include <stdio.h>
#include <math.h>
int main() {  
    int x,y;
    scanf("%d %d", &x, &y);
    int a = 2*x*y-12;
    int b = (3*pow(x, 2))- (12*pow(y,3))+(21*x)+(2*y);
    printf("%d %d", a,b);
    return 0;
}
