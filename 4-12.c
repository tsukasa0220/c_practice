#include <stdio.h>

int main(void) {
    int no;
    int cnt=0;
    do{
        printf("³‚Ì®”‚ğ“ü—Í‚¹‚æ:");
        scanf("%d",&no);
        if(no<=0){
            puts("³‚Å‚È‚¢”‚ğ‚ğ“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢B");
        }
    }while(no<=0);
    printf("%d‚Í",no);
    while(no>0){
       no/=10;
       cnt++; 
    }
    printf("%dŒ…‚Å‚·B\n",cnt);

    return 0;
}