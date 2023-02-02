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

    puts("科目の合計点");
    printf("国語：%d点\n", sum_japanese);
    printf("数学：%d点\n", sum_math);
    
    puts("科目の平均点");
    printf("国語：%d点\n", sum_japanese / 6);
    printf("数学：%d点\n", sum_math / 6);
    
    puts("学生の合計点");
    for (int i = 0; i < 6; i++) {
        printf("%d人目：%d点\n", i + 1, sum_student[i]);
    }

    puts("学生の平均点");
    for (int i = 0; i < 6; i++) {
        printf("%d人目：%d点\n", i + 1, sum_student[i] / 2);
    }
    return 0;
}