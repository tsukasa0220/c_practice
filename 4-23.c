#include <stdio.h>
int main(void) {
    int len;
    puts("���㒼�p�񓙕ӎO�p�`��\�����܂��B");
    printf("�Z�ӁF");
    scanf("%d",&len);
    for(int i=len;i>0;i--){
        for(int j=i;j>0;j--){
            putchar('*');
        }
        putchar('\n');
    }


    puts("�E�㒼�p�񓙕ӎO�p�`��\�����܂��B");
    printf("�Z�ӁF");
    scanf("%d",&len);
    for(int i=1;i<=len;i++){
        for(int j=2;j<=i;j++){
            putchar(' ');
        }
        for(int j=0;j<=len-i;j++){
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}