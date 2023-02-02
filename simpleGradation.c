#include <stdio.h>
#include "svg.h"

int main(void)
{
    int n = 12;

    start();
    strokeWeight(1);
    for (int i = 0; i <= n; i++) {
        fill(hsl360(i * 15, 100, 50));
        stroke(hsl360(120 + i * 15, 100, 50));
        rect(150 - 5 * i, 30 + 6 * i, 40 + 10 * i, 5);
    }
    finish();
    return 0;
}