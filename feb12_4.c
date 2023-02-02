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

    printf("a �� b �ɂ��Ă�");
    if (bar(a, b, 6)) {
        printf("���藧�B\n");
    } else {
        printf("���藧���Ȃ��B\n");
    }

    printf("a �� c �ɂ��Ă�");
    if (bar(a, c, 6)) {
        printf("���藧�B\n");
    } else {
        printf("���藧���Ȃ��B\n");
    }

    return 0;
}