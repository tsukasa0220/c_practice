#include <stdio.h>

void foo(int n) 
{
    int a = 1;
    int b = -1;
    for (int k = 2; k <= n + 1; k++) {
        printf("%d ", a);

        a = k * a + b;
        b = -k * b;
    }
}

int main(void) {
    int n;

    printf("���̐�������͂��Ă�������: ");
    scanf("%d", &n);

    foo(n);
    putchar('\n');

    return 0;
}