#include <stdio.h>
int main(void) {
    int n;
    int sum=0;
    printf("n�̒l:"); 
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    printf("1����%d�܂ł̑��a��%d�ł��B\n",n,sum);
    return 0;
}