#include <stdio.h>

int main(void) {
    int cnt1=0;
    int cnt=-1;
    int no;
    do{
        printf("®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢i•‰‚Ì”‚Å“ü—ÍI—¹j:"); 
        scanf("%d",&no);
        if(no>=50){
            cnt1++;
        }
        cnt++;
    }while(no>=0);

    printf("50ˆÈã‚Ì”‚ÌŠ„‡‚Í%f%%‚Å‚·\n",(double)cnt1/cnt*100);
    return 0;
}