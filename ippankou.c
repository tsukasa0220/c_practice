#include <stdio.h>
int main(void) {
    int no;
    printf("���̐�������͂��Ă�������:");
    scanf("%d",&no);
    for(int i=1;i<=no;i++){
        printf("��%d����%d\n",i,i*i+7*i-19);
    }
    putchar('\n');
    return 0;
}