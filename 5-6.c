#include <stdio.h>
#define NUMBER 99
int main(void) {
    int n;
    int data[NUMBER];
    printf("データ数：");
    do {
        scanf("%d", &n);
        if (n < 1 || n > NUMBER) {
            printf("1~99で入力してください：");
        }
    } while (n < 1 || n > NUMBER); 
    for (int i = 0; i < n; i++) {
        printf("%2d番：", i + 1);
        scanf("%d", &data[i]);
    }
    printf("{");
    for (int i = 0; i < n; i++) {
       printf("%d", data[i]);
       if (i >= n - 1) {
           break;
       }
       printf(", ");
    }
    printf("}\n");
    return 0;
}