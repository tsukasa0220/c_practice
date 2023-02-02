#include <stdio.h>

int main(void)
{
    int ch, cnt = 0;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            cnt++;
        }
    }
    printf("s”‚Í%ds‚Å‚·B\n", cnt);
    return 0;
}