#include <stdio.h>
int main(void) {
    int no;
    printf("‰½ŒÂn‚ð•\Ž¦‚µ‚Ü‚·‚©:");
    scanf("%d",&no);
    for(int i=1;i<=no;i++){
        putchar('*');
        if(i%5==0){
            putchar('\n');
        }
    }
    putchar('\n');
    return 0;
}