#include <stdio.h>

int productSoFar(int no)
{
    static int s = 1;
    int tmp;
    if (no == 0) {
        tmp = s;
        s = 1;
        return tmp;
    }else {
        return s = s * no;
    }
    
}
int main(void)
{
    int no, retry;
    do {
        printf("整数を入力してください：");
        scanf("%d", &no);
        printf("これまでの入力の積は%dです。\n", productSoFar(no));
        printf("入力を続けますか？(Yes -> 0/No -> 9)：");
        scanf("%d", &retry);
    }while (retry == 0);
    puts("終了します。");

    return 0;
}