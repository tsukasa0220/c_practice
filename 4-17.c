#include <stdio.h>
int main(void) {
    int n;
    printf("n‚Ì’l:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d‚Ì2æ‚Í%d\n",i,i*i);
    }
    return 0;
}