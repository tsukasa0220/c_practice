#include <stdio.h>
#include "svg.h"

int main(void)
{
    start();
    stroke(hsl360(20, 20, 80));
    fill(hsl360(20, 20, 80));
    rect(0, 0, 100, 100);

    stroke(hsl360(120, 5, 60));
    fill(hsl360(120, 5, 60));
    rect(0, 0, 50, 100);

    fill(hsl360(260, 10, 25));    
    stroke(hsl360(260, 10, 25));
    triangle(-50, 100, 50, 50, 150, 100);

    stroke(hsl360(120, 5, 100));
    fill(hsl360(120, 5, 100));
    rect(101, 0, 100, 100);

    stroke(hsl360(10, 20, 50));
    fill(hsl360(10, 20, 50));
    ellipse(50, 50, 60, 60);

    finish();
    return 0;
}