#include <stdio.h>
#include <math.h>

int main(void)
{
    double s;
    do {
        printf("面積を入力してください：");
        scanf("%lf", &s);
        if (s < 0) {
            printf("負の値を入力しないでください：");
        }
    }while (s < 0);
 
    printf("その面積を持つ正方形の一辺の長さは%fです。\n", sqrt(s));

    return 0;
}