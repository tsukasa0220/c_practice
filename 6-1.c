#include <stdio.h>

int min2(int a, int b)
{
    int min = a;
    if (b < min) {
        min = b;
    }
    return min;
}

int main(void) 
{
	int a, b;
    
    puts("��̐�������͂���B");
    printf("����a�F");
    scanf("%d", &a);
    printf("����b�F");
    scanf("%d", &b);

    printf("�ŏ��l��%d�ł��B\n", min2(a, b));

    return 0;
}