#include <stdio.h>
#include "svg.h"

int main(void)
{
    int cnt = 0;
    start();

    fill(hsl360(0, 0, 50));
    rect(centerX() - 50, centerY() - 50, 100, 100);
    translate(centerX(), centerY());
    pushMatrix();
    for (int i = 0; i < 12 ; i++) {
        popMatrix(); 
        if (cnt % 2 == 0) {
            stroke(hsl360(0, 100, 100));
        }else {
            stroke(hsl360(0, 100, 0));
        }
        noFill();
        rect(30, 30 , 5, 5);
        rotate360(30);

        pushMatrix();
        cnt++;
    }

    finish();

    return 0;
}