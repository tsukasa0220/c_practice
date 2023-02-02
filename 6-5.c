#include <stdio.h>

int sumup(int a)
{
    int sum = 0;

    for (int i = 1; i <= a; i++) {
        sum += i;
    }
    return sum;
}

int main(void) 
{
    int a;

	printf("®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F");
    scanf("%d", &a);

    printf("1‚©‚ç%d‚Ü‚Å‚Ì‘S®”‚Ì˜a‚Í%d‚Å‚·B\n", a, sumup(a));
    
    return 0;
}