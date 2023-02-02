#include <stdio.h>
int main(void) {
    int len,i,j,k=1;
    printf("®”‚ğ“ü—Í‚µ‚Ä‰º‚³‚¢:");
    scanf("%d",&len);
    for(i=1;i<=len;i++){
        for(j=1;j<=i;j++){
            printf("%d",(3*k-2)%10);
            k++;
        }
        putchar('\n');
    }
    printf("end\n");
    return 0;
}