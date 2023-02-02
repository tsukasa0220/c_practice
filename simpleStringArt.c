#include <stdio.h>
#include "svg.h"

int main(void)
{
    start();
    double n = 50;

    for (int i = 0; i <= n; i++) {
        stroke(hsb360(i * 7, 100, 100));
        line(40 + (200 * i) / n, 25 + (160 * (n - i)) / n, 40 + (200 * (n - i)) / n, 185);
    }
     
    finish();
    return 0;
}