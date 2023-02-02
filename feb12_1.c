#include <stdio.h>

int main(void)
{
    int n;
    printf("³‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0 && i % 3 != 0) {
            putchar('*');
        } else {
            printf("%d", i);
        }
        putchar(' ');
    }
    putchar('\n');

    return 0;
}