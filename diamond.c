#include "svg.h"

int main(void) {
    int n = 11, i, j;
    int r = 100;     /* 半径 */
    double cx = (297.0 / 2), cy = (210.0 / 2); /* 中心 */

    start();
    stroke(hsl360(180, 100, 50));

    for (i = 0; i < n; i++) {
        double kaku1 = 360.0 *  i / n;
        for (j = i + 1; j < n; j++) {
            double kaku2 = 360.0 *  j / n;  /* cos360, sin360 は svg.hに宣言されている */
            line(cx + r * cos360(kaku1), cy + r * sin360(kaku1), 
                 cx + r * cos360(kaku2), cy + r * sin360(kaku2));
        }
    }

    finish();
    return 0;
}
