#include <stdio.h>

int main(void) {
    int no1,no2;
    puts("“ñ‚Â‚Ì‚O‚Ü‚½‚Í³‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B");
    printf("®”‚P:"); scanf("%d",&no1);
    printf("®”‚Q:"); scanf("%d",&no2);

    if(no1%2==0&&no2%2==0){
        puts("—¼•û‚Ì”‚ª‹ô”‚Å‚·B");
    }else{
        puts("­‚È‚­‚Æ‚àˆê•û‚Ì”‚ª‹ô”‚Å‚Í‚ ‚è‚Ü‚¹‚ñB");
    }
    
    return 0;
}