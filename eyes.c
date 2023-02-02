#include <stdio.h>
#include "svg.h"

void generate(int d, double x, double y, double r) {
    if (d <= 0) {
        return;
    }
    stroke(hsl360(d * 70, 100, 50));
    ellipse(x, y, r, r);
    generate(d - 1, x - r / 4, y, r / 2);
    generate(d - 1, x + r / 4, y, r / 2);
}


int main(void) {
    start();
    
    strokeWeight(0.5);
    noFill();

    generate(5, WIDTH / 2.0, HEIGHT / 2.0, 140);
    
    finish();
    return 0;
}