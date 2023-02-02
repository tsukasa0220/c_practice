#include <stdio.h>

int main(void) {
	int no;
    printf("整数を入力してください:"); scanf("%d",&no);

    if (no<0){
        puts("負の値が入力されました。");
    }else if (no%5==0){
        puts("その数は5で割り切れます。");
    }else {
        printf("その数を5で割った余りは%dです。\n",no%5);
    }

    return 0;
}