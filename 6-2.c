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
    
    puts("��̐�������͂���B");
    printf("����a�F");
    scanf("%d", &a);
    printf("����b�F");
    scanf("%d", &b);
    printf("����c�F");
    scanf("%d", &c);

    printf("�ŏ��l��%d�ł��B\n", min3(a, b, c));

    return 0;
}