#include <stdio.h>

int bar(const int va[], const int vb[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += va[i];
        if (sum >= vb[i]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {

    int a[6] = { 1, 2, 4, 8, 16, 32 };
    int b[6] = { 2, 4, 8, 16, 32, 64 };
    int c[6] = { 2, 4, 8, 15, 999, 999 };

    printf("a と b については");
    if (bar(a, b, 6)) {
        printf("成り立つ。\n");
    } else {
        printf("成り立たない。\n");
    }

    printf("a と c については");
    if (bar(a, c, 6)) {
        printf("成り立つ。\n");
    } else {
        printf("成り立たない。\n");
    }

    return 0;
}