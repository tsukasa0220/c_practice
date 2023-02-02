#include <stdio.h>
int main(void) {
    int len;
    puts("³•ûŒ`‚ğì‚è‚Ü‚·B");
    printf("‰½’i‚Å‚·‚©:");
    scanf("%d",&len);
    for(int i=1;i<=len;i++){
        for(int j=1;j<=len;j++){
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}