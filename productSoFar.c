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
        printf("��������͂��Ă��������F");
        scanf("%d", &no);
        printf("����܂ł̓��͂̐ς�%d�ł��B\n", productSoFar(no));
        printf("���͂𑱂��܂����H(Yes -> 0/No -> 9)�F");
        scanf("%d", &retry);
    }while (retry == 0);
    puts("�I�����܂��B");

    return 0;
}