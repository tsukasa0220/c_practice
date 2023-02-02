#include <stdio.h>
int main(void) {
    int len1,len2;
    puts("正方形を作ります。");
    printf("一辺（その１）:");
    scanf("%d",&len1);
    printf("一辺（その２）:");
    scanf("%d",&len2);
    int width=len1,height=len2;
    if(width<height){
        width=len2;
        height=len1;
    }
    for(int i=1;i<=height;i++){
        for(int j=1;j<=width;j++){
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}