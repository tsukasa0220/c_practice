#include <stdio.h>
int main(void) {
    int no;
    int tousa=0;
    printf("������͂��Ă�������:");
    scanf("%d",&no);
    for(int cnt=1;cnt<=no;cnt++){
        printf("%d ",tousa);
        tousa+=7;
    }
    putchar('\n');
    return 0;
}