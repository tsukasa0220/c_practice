#include <stdio.h>
int main(void) {
    int n;
    printf("n�̒l:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        printf("%d��2���%d\n",i,i*i);
    }
    return 0;
}