#include "svg.h"

int main(void) {
    int n = 7, i;
    int r = 100, cx = 297.0 / 2, cy = 210.0 / 2;

    start();
    stroke(hsl360(180, 100, 50));

    for(i = 0; i < n; i++) {
        double theta1 = 360.0 *  i / n;
        double theta2 = 360.0 *  (i + 1) / n;
        line(cx + r * cos360(theta1), cy + r * sin360(theta1),
             cx + r * cos360(theta2), cy + r * sin360(theta2));
    }

    finish();
    return 0;
}
