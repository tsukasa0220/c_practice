#include <stdio.h>

int min3(int a, int b, int c)
{
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

int main(void) 
{
	int a, b, c;
    
    puts("二つの整数を入力せよ。");
    printf("整数a：");
    scanf("%d", &a);
    printf("整数b：");
    scanf("%d", &b);
    printf("整数c：");
    scanf("%d", &c);

    printf("最小値は%dです。\n", min3(a, b, c));

    return 0;
}