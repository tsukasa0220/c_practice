#include <stdio.h>
int main(void) {
    int no;
    int a=2;
    printf("���̐�������͂��Ă�������:");
    scanf("%d",&no);
    for(int i=1;i<=no;i++){
        printf("��%d����%d\n",i,a);
        a=2*a+7;
    }
    putchar('\n');
    return 0;
}