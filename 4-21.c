#include <stdio.h>
int main(void) {
    int len;
    puts("�����`�����܂��B");
    printf("���i�ł���:");
    scanf("%d",&len);
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}