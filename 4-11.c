#include <stdio.h>

int main(void) {
    int no;

    do{
        printf("³‚Ì®”‚ğ“ü—Í‚¹‚æ:");
        scanf("%d",&no);
        if(no<=0){
            puts("³‚Å‚È‚¢”‚ğ‚ğ“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B");
        }
    }while(no<=0);

    printf("%d‚ğ¶‚©‚ç“Ç‚Ş‚Æ",no);
    while(no>0){
        printf("%d",no%10);
        no/=10;
    }
    puts("‚Å‚·B");
    return 0;
}