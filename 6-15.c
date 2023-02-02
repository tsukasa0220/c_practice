#include <stdio.h>

void put_count(void)
{
    static int count = 1;
    printf("put_count: %d‰ñ–Ú\n", count++);
}

int main(void)
{
    put_count();
    put_count();
    put_count();
    
    return 0;
}