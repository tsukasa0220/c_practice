#include <stdio.h>

int sqr(int x)
{
    return x * x;
}

int pow4(int x)
{
    return sqr(x) * sqr(x);
}

int main(void) 
{
    int x;

    printf("��������͂���F");
    scanf("%d", &x);

    printf("x�̂S���%d�ł��B\n", pow4(x));
	
    return 0;
}