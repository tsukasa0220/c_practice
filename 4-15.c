#include <stdio.h>
int main(void) {
    int from;
    int to;
    int add;
    printf("��cm����:"); scanf("%d",&from);
    printf("��cm�܂�:"); scanf("%d",&to);
    printf("��cm����:"); scanf("%d",&add);
    for(int i=from;i<=to;i+=add){
        printf("%dcm�@%.2fkg\n",i,(i-100)*0.9);
    }
    return 0;
}