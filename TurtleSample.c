#include "svg.h"

int main(void){
    int i;

    start();                     /* 最初に必要 */

    for(i = 1; i <= 24; i++) {
        stroke(hsl360(i * 15, 100, 50));
        forward(i * 5);
        turn(90);
    }

    finish();                    /* 最後に必要 */
    return 0;
}    
