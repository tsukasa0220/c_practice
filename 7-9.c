#include <stdio.h>
#include <math.h>

int main(void)
{
    double s;
    do {
        printf("�ʐς���͂��Ă��������F");
        scanf("%lf", &s);
        if (s < 0) {
            printf("���̒l����͂��Ȃ��ł��������F");
        }
    }while (s < 0);
 
    printf("���̖ʐς��������`�̈�ӂ̒�����%f�ł��B\n", sqrt(s));

    return 0;
}