#include <stdio.h>
int main(void) {
    int no;
    printf("³‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢:");
    scanf("%d",&no);
    for(int i=1;i<=no;i++){
        printf("‘æ%d€‚Í%d\n",i,i*i+7*i-19);
    }
    putchar('\n');
    return 0;
}