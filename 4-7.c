#include <stdio.h>

int main(void) {
    int no;
    printf("³‚Ì®”‚ð“ü—Í‚¹‚æ:"); scanf("%d",&no);
    int i=2;
    while(no>=2&&i<=no){
        printf("%d",i);
        i*=2;
    }
    printf("\n");
    return 0;
}