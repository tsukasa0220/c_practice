#include <stdio.h>

#define NUMBER 7

int search_idx(const int v[], int idx[], int key, int n)
{
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == key) {
            idx[x++] = i;
        }
    }
    return x;
}

int main(void)
{
    int v[NUMBER] = {1, 7, 5, 7, 2, 4, 7};
    int idx[NUMBER];
    int key;
    int x;
    printf("’T‚·’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢F");
    scanf("%d", &key);
    x = search_idx(v, idx, key, NUMBER);
    printf("{");
    for (int i = 0; i < x; i++) {
        printf("%d,", idx[i]);
    }
    puts("}");
    printf("ŒÂ”‚Í%d", x);

    return 0;
}