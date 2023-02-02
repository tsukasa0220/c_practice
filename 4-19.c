#include <stdio.h>
int main(void) {
    int no;
    int cnt=0;
    printf("®”’l:");
    scanf("%d",&no);
    for(int i=1;i<=no;i++){
        if(no%i==0){
            printf("%d\n",i);
            cnt++;
        }
    }
    printf("–ñ”‚Í%dŒÂ‚Å‚·B",cnt);
    return 0;
}