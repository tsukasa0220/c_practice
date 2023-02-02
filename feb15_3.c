#include <stdio.h>

int foo(int m, int n)
{
    int k = 0;
    while (n % m == 0) {
        k++;
        n = n / m;
    }
    return k;
}

int main(void) {
    int m, n, k;
    printf("³‚Ì®” 1 ‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢: ");
    scanf("%d", &m);
    printf("³‚Ì®” 2 ‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢: ");
    scanf("%d", &n);
    k = foo(m, n);
    printf("%d ‚Ì %d æ‚Í %d ‚ğŠ„‚èØ‚è‚Ü‚·B\n", m, k, n);

    return 0;
}