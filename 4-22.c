#include <stdio.h>
int main(void) {
    int len1,len2;
    puts("�����`�����܂��B");
    printf("��Ӂi���̂P�j:");
    scanf("%d",&len1);
    printf("��Ӂi���̂Q�j:");
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