#include <stdio.h>

int scan(void)
{
    int tmp;
    static int cnt = 1;
    
    do {
        printf("®”%dG", cnt);
        scanf("%d", &tmp);
        if (tmp < 0) {
            puts("”ñ•‰‚Ì®”‚Å“ü—Í‚µ‚Ä‚­‚¾‚³‚¢");
        }
    } while (tmp < 0);
    cnt++;
    return tmp;
}

int gcd(int x, int y)
{
    if (y != 0 && x % y > 0) {
        return gcd(y, x % y);
    } else {
        return y;
    }
}

int main(void)
{
    puts("”ñ•‰‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢");
    int x = scan();
    int y = scan();

    printf("Å‘åŒö–ñ”‚Í%d‚Å‚·B\n", gcd(x >= y ? x : y, x >= y ? y : x));

    return 0;
}