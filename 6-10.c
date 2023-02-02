#include <stdio.h>

#define NUMBER 5

void intary_rcpy(int v1[], const int v2[], int n)
{
    for (int i = 0; i < n; i++) {
        v1[n - i - 1] = v2[i];
    }
}

void print(const int v[], int n)
{
    puts("”½“]‚µ‚Ü‚µ‚½B");
    for (int i = 0; i < n; i++) {
        printf("b[%d] = %d\n", i, v[i]);
    }
}

int main(void)
{
    int a[NUMBER];
    int b[NUMBER];
    for (int i = 0; i < NUMBER; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    intary_rcpy(b, a, NUMBER);

    print(b, NUMBER);

    return 0;
}