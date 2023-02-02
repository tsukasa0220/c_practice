#include <stdio.h>

int main(void) {
    int no;
    printf("³‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢:");
    scanf("%d",&no);
    int i=1;
    while(i<no){
        printf("%d",i);
        i*=2;
    }
    puts("");

    return 0;
}