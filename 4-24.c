#include <stdio.h>
int main(void) {
    int len;
    puts("�s���~�b�h�����܂��B");
    printf("���i�ł����F");
    scanf("%d",&len);
    for(int i=1;i<=len;i++){
        for(int j=len;j>i;j--){
            putchar(' ');
        }
        for(int j=1;j<=(i-1)*2+1;j++){
            putchar('*');
        }
        putchar('\n');
        
    }
    return 0;
}