#include <stdio.h>

int main(void)
{
    float x1 = 0.0, x2 = 0;

    for (int i = 0; i <= 200; i++) {
        x2 = i / 100.0;
        printf("x = %f  x = %f\n", x1, x2);
        x1 += 0.01; 
    }
    return 0;
}