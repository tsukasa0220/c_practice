#include <stdio.h>

int sumup(int a)
{
    int sum = 0;

    for (int i = 1; i <= a; i++) {
        sum += i;
    }
    return sum;
}

int main(void) 
{
    int a;

	printf("��������͂��Ă��������F");
    scanf("%d", &a);

    printf("1����%d�܂ł̑S�����̘a��%d�ł��B\n", a, sumup(a));
    
    return 0;
}