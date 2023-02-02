#include <stdio.h>
int main(void) {
    int len;
    puts("ピラミッドを作ります。");
    printf("何段ですか：");
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