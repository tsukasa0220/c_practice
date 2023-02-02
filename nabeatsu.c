#include <stdio.h>
int main(void) {
    int no1, no2, i, j;
    printf("®”‚P‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢:");
    scanf("%d", &no1);
    printf("®”‚Q‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢:");
    scanf("%d", &no2);
    
    for(i = no1; i <= no2; i++) {
        printf("%d", i);
        j = i;
        if(j % 3 == 0) {
            printf("^^;");     
        } else {
            if(j < 0) {
                j = -j;
            }
            while(j > 0) {
                if(j % 10 == 3) {
                    printf("^^;");
                    break;
                }
                j /= 10;
            }
        }
        putchar(' ');
    }
    putchar('\n');

    return 0;
}