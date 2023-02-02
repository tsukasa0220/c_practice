#include <stdio.h>

int whichPlanet(void)
{
    int n;
    printf("���z�n�扽�f���ł����H1����8�̐�������͂��ĉ�����:");
    do {
        scanf("%d", &n);
        if (n < 1 || n > 8) {
            printf("���z�n�扽�f���ł����H1����8�̐�������͂��ĉ�����:");
        }
    } while (n < 1 || n > 8);
    return n;
}

void showPlanet(int p)
{
    switch(p){
            case 1:printf("����"); break;
            case 2:printf("����"); break;
            case 3:printf("�n��"); break;
            case 4:printf("�ΐ�"); break;
            case 5:printf("�ؐ�"); break;
            case 6:printf("�y��"); break;
            case 7:printf("�V����"); break;
            case 8:printf("�C����"); break;
    }
}

int main(void)
{
    int rank[] = { 8, 6, 5, 7, 1, 2, 3, 4 };
    int p1, p2;
    printf("1�߂�");   
    p1 = whichPlanet();
    printf("2�߂�"); 
    p2 = whichPlanet();

    if (rank[p1 - 1] > rank[p2 - 1]) {
        
        int tmp = p1;
	    p1 = p2; 
        p2 = tmp;
    }

    showPlanet(p1);
    printf("�̂ق���");
    showPlanet(p2);
    puts("�����傫���ł��B");

    return 0;
}