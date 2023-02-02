#include "svg.h"
#define N 10
#define UNIT_X 2
#define UNIT_Y 10
#define MARGIN_X 15
#define MARGIN_Y 15

int main(void) {
    int i;
    int data[N] = {24, 89, 63, 72, 99, 19, 53, 61, 55, 41};

    start();
    stroke(hsl360(180, 100, 50));
    fill(hsl360(0, 100, 50));

    for (i = 0; i < N; i++) {
        rect(MARGIN_X, MARGIN_Y + i * UNIT_Y, data[i] * UNIT_X, UNIT_Y);
    }

    finish();
    return 0;
}
