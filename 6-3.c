#include <stdio.h>
int cube(int x) 
{
    return x * x * x;
}
int main(void) 
{
    int x;

	printf("��������͂���F");
    scanf("%d", &x);

    printf("x�̂R���%d�ł��B\n", cube(x));
    return 0;
}