#include <stdio.h>

int chome(int k)
{
    int a = 1;
    for (int i = 0; i < k; i++) {
        a = (2 * a * a + 1) % (i + 4);
    }
    return a;
}

int main(void)
{
    int data[] = {10, 100, 1000, 10000};

    for (int i = 0; i < 4; i++) {
	int n = data[i];
	int a = chome(n);
	printf("a_{%d} = %d\n", n, a); 
    }
    return 0;
}