#include <stdio.h>

int main(void) 
{
	int tensu[6][2] = { {91, 63}, {67, 72}, {89, 34}, {32, 54}, {97, 67}, {73, 43} }; 
    int sum_japanese = 0;
    int sum_math = 0;
    int sum_student[6] = {0};
 
    for (int i = 0; i < 6; i++) {
        sum_japanese += tensu[i][0];
        sum_math += tensu[i][1];
        sum_student[i] = tensu[i][0] + tensu[i][1];
    }

    puts("�Ȗڂ̍��v�_");
    printf("����F%d�_\n", sum_japanese);
    printf("���w�F%d�_\n", sum_math);
    
    puts("�Ȗڂ̕��ϓ_");
    printf("����F%d�_\n", sum_japanese / 6);
    printf("���w�F%d�_\n", sum_math / 6);
    
    puts("�w���̍��v�_");
    for (int i = 0; i < 6; i++) {
        printf("%d�l�ځF%d�_\n", i + 1, sum_student[i]);
    }

    puts("�w���̕��ϓ_");
    for (int i = 0; i < 6; i++) {
        printf("%d�l�ځF%d�_\n", i + 1, sum_student[i] / 2);
    }
    return 0;
}