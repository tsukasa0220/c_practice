#include <stdio.h>

int main(void)
{
    int n;
    printf("�񕉂̐�������͂��Ă��������F");
    scanf("%d", &n);

    for (int i = 1; i <= n; i += 2) {
        for (int j = n; j >= i; j--) {
            printf("%d", j % 10);
        }
        putchar('\n');
    }
    puts("end");

    return 0;
}