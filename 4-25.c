#include <stdio.h>
int main(void) {
    int len;
    puts("�����������s���~�b�h�����܂��B");
    printf("���i�ł����F");
    scanf("%d",&len);
    for(int i=1;i<=len;i++){
        for(int j=2;j<=i;j++){
            putchar(' ');
        }
        for(int j=1;j<=(len-i)*2+1;j++){
            printf("%d",i%10);
        }
        putchar('\n');
    }
    return 0;
}