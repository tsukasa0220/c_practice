#include <stdio.h>

int foo(int m, int n)
{
    int k = 0;
    while (n % m == 0) {
        k++;
        n = n / m;
    }
    return k;
}

int main(void) {
    int m, n, k;
    printf("���̐��� 1 ����͂��Ă�������: ");
    scanf("%d", &m);
    printf("���̐��� 2 ����͂��Ă�������: ");
    scanf("%d", &n);
    k = foo(m, n);
    printf("%d �� %d ��� %d ������؂�܂��B\n", m, k, n);

    return 0;
}