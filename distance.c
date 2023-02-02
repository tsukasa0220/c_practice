#include <stdio.h>

int main(void) {
	double no;
    printf("何メートル離れていますか？"); scanf("%lf",&no);

    if (no<1.0){
        puts("そんなにくっつかないでください。");
    }else if(no<2.5){
        puts("もう少し離れてください。");
    }else if(no<4.0){
        puts("もう少しだけ離れるほうが安全です。");
    }else {
        puts("安全な距離です。");
    }
    return 0;
}