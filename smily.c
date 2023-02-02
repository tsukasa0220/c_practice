#include <stdio.h>

void smily(int n)
{
    for (int i = 1; i <= n /3; i++) {
        printf("^^;");
    }
    for (int i = 1; i <= n % 3; i++) {
        putchar(';');
    }
}

void put_chars(int n)
{
    while (n-- > 0)
		putchar(' ');
}

int main(void)
{
    int i, n;
    printf("®”‚ğ“ü—Í‚µ‚Ä‰º‚³‚¢: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {
        smily(i);
        put_chars(n - i);
        put_chars(n - i);
        smily(i);
        putchar('\n');
    }

    return 0;
}