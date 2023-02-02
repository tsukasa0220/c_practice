#include <stdio.h>

int sqr(int x)
{
    return x * x;
}

int pow4(int x)
{
    return sqr(x) * sqr(x);
}

int main(void) 
{
    int x;

    printf("®”‚ğ“ü—Í‚¹‚æF");
    scanf("%d", &x);

    printf("x‚Ì‚Sæ‚Í%d‚Å‚·B\n", pow4(x));
	
    return 0;
}