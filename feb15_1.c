#include <stdio.h>

int main(void)
{
    int n;
    printf("³‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d", i);
        if (i % 3 == 0 || i % 5 == 0) {
            putchar('#');
        } else {
            putchar(' ');
        }
    }
    putchar('\n');

    return 0;
}