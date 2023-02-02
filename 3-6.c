#include <stdio.h>

int main(void) {
	
    int a,b,c;
    printf("®”‚PF"); scanf("%d",&a);
    printf("®”‚QF"); scanf("%d",&b);
    printf("®”‚RF"); scanf("%d",&c);

    int min;
    if (a>b) min=b;
    if (b>c) min=c;
    else min=a;
    printf("Å¬’l‚Í%d‚Å‚·B\n",min);
    
    return 0;
}