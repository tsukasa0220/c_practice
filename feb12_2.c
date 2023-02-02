#include <stdio.h>

int main(void)
{
    int n;
    printf("”ñ•‰‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
       for (int j = n - i + 1; j > 0; j--) {
           printf("%d", j % 10);
       }
       putchar('\n');
       if (i % 4 == 0) {
           putchar('\n');
       }
    }

    puts("end");

    return 0;
}