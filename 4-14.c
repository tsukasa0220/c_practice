#include <stdio.h>
int main(void) {
    int no;
    printf("³‚Ì®”‚ğ“ü—Í‚¹‚æ:");
    scanf("%d",&no);
    for(int i=1;i<=no;i++){
        printf("%d",i%10);
    }
    putchar('\n');
    return 0;
}