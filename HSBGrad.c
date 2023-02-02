#include <stdio.h>
#include <math.h>
#include "svg.h"


int main(void){
    int i,j;
    int x0 = 44, y0 = 32;
    
    start();

    noStroke();
    textFont("Verdana", 12);
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 15; j++) {
            fill(hsl100(i * 5, j * 100.0 / 14, 50));
            text("&#x2603;", x0 + i * 10, y0 + j * 10);  /* &#x2603;は雪だるまを表す文字 */
        }
    }

    finish();
    return 0;
}
