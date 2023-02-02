#include <stdio.h>
int main(void) {
    int no;
    int a=2;
    printf("³‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢:");
    scanf("%d",&no);
    for(int i=1;i<=no;i++){
        printf("‘æ%d€‚Í%d\n",i,a);
        a=2*a+7;
    }
    putchar('\n');
    return 0;
}