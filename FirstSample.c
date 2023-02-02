#include "svg.h"

int main(void){
    start();                     /* 最初に必要 */
    
    strokeWeight(1);             /* 線の太さ */
    stroke(hsl360(0, 100, 50));  /* 線の色 */
    fill(hsl360(180, 50, 50));   /* 塗りの色 */ 
    rect(70, 50, 60, 70);        /* 長方形 */

    stroke(hsl360(120, 100, 50));
    fill(hsl360(300, 50, 50));
    ellipse(210, 85, 60, 70);    /* 楕円 */

    stroke(hsl360(60, 100, 50));
    line(60, 160, 160, 160);     /* 直線 */

    noStroke();
    fill(hsl360(240, 100, 50));
    textFont("Times New Roman", 12);
    text("ABCxyz12345&#x2600;&#x2602;", 60, 160); 
    /* 文字列 */
    finish();                    /* 最後に必要 */
    return 0;
}
