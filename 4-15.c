#include <stdio.h>
int main(void) {
    int from;
    int to;
    int add;
    printf("‰½cm‚©‚ç:"); scanf("%d",&from);
    printf("‰½cm‚Ü‚Å:"); scanf("%d",&to);
    printf("‰½cm‚²‚Æ:"); scanf("%d",&add);
    for(int i=from;i<=to;i+=add){
        printf("%dcm@%.2fkg\n",i,(i-100)*0.9);
    }
    return 0;
}