#include <stdio.h>
int main(void) {
    int a[5];
    int tousa = 7;
    for(int i = 0; i < 5; i++) {
        a[i] = tousa;
        tousa -= 4;
    }
    for (int i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    return 0;
}