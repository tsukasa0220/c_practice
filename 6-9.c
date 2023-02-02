#include <stdio.h>

#define NUMBER 5

void rev_intary(int v[], int n)
{
    int tmp;

    for (int i = 0; i < n / 2; i++) {
        tmp = v[i];
        v[i] = v[n - i - 1];
        v[n - i - 1] = tmp;
    }
}

void print(const int v[], int n)
{
    puts("”½“]‚µ‚Ü‚µ‚½B");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d\n", i, v[i]);
    }    
}
int main(void)
{
    int a[NUMBER];

    for (int i = 0; i < NUMBER; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    rev_intary(a, NUMBER);

    print(a, NUMBER);

    return 0;
}