#include <stdio.h>

void printSenary(int n)
{
    if (n >= 6) {
        printSenary(n / 6);
    }
    printf("%d", n % 6);
}


int main(void)
{
    int no;
    printf("��������͂��Ă��������F");
    do {
        scanf("%d", &no);
        if (no < 0) {
            printf("�񕉂̐�������͂��Ă��������F");
        }
    }while (no < 0);
    printf("���̐���6�i���ɂ��\����");
    printSenary(no);
    printf("�ł��B\n");

    return 0;
}