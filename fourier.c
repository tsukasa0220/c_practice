#include <stdio.h>
#include <math.h>
#define NUMBER 7

int main(void)
{
    for (int i = -50; i <= 50; i++) {
        double x = 0.2 * i; 
        double y = 0;
        for (int k = 1; k <= NUMBER; k++) {
            y += sin(k * x) / k;
        }
        printf("%f %f\n", x, y);
    }
    
    return 0;
}