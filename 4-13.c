#include <stdio.h>
int main(void) {
    int n;
    int sum=0;
    printf("n‚Ì’l:"); 
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    printf("1‚©‚ç%d‚Ü‚Å‚Ì‘˜a‚Í%d‚Å‚·B\n",n,sum);
    return 0;
}