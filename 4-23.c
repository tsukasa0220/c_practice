#include <stdio.h>
int main(void) {
    int len;
    puts("左上直角二等辺三角形を表示します。");
    printf("短辺：");
    scanf("%d",&len);
    for(int i=len;i>0;i--){
        for(int j=i;j>0;j--){
            putchar('*');
        }
        putchar('\n');
    }


    puts("右上直角二等辺三角形を表示します。");
    printf("短辺：");
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