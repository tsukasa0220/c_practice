#include <stdio.h>

int scan(void)
{
    int tmp;
    static int cnt = 1;
    
    do {
        printf("����%d�G", cnt);
        scanf("%d", &tmp);
        if (tmp < 0) {
            puts("�񕉂̐����œ��͂��Ă�������");
        }
    } while (tmp < 0);
    cnt++;
    return tmp;
}

int gcd(int x, int y)
{
    if (y != 0 && x % y > 0) {
        return gcd(y, x % y);
    } else {
        return y;
    }
}

int main(void)
{
    puts("�񕉂̐�������͂��Ă�������");
    int x = scan();
    int y = scan();

    printf("�ő���񐔂�%d�ł��B\n", gcd(x >= y ? x : y, x >= y ? y : x));

    return 0;
}