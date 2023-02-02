#include <stdio.h>

int whichPlanet(void)
{
    int n;
    printf("‘¾—zŒn‘æ‰½˜f¯‚Å‚·‚©H1‚©‚ç8‚Ì®”‚ğ“ü—Í‚µ‚Ä‰º‚³‚¢:");
    do {
        scanf("%d", &n);
        if (n < 1 || n > 8) {
            printf("‘¾—zŒn‘æ‰½˜f¯‚Å‚·‚©H1‚©‚ç8‚Ì®”‚ğ“ü—Í‚µ‚Ä‰º‚³‚¢:");
        }
    } while (n < 1 || n > 8);
    return n;
}

void showPlanet(int p)
{
    switch(p){
            case 1:printf("…¯"); break;
            case 2:printf("‹à¯"); break;
            case 3:printf("’n‹…"); break;
            case 4:printf("‰Î¯"); break;
            case 5:printf("–Ø¯"); break;
            case 6:printf("“y¯"); break;
            case 7:printf("“V‰¤¯"); break;
            case 8:printf("ŠC‰¤¯"); break;
    }
}

int main(void)
{
    int rank[] = { 8, 6, 5, 7, 1, 2, 3, 4 };
    int p1, p2;
    printf("1‚Â‚ß‚Í");   
    p1 = whichPlanet();
    printf("2‚Â‚ß‚Í"); 
    p2 = whichPlanet();

    if (rank[p1 - 1] > rank[p2 - 1]) {
        
        int tmp = p1;
	    p1 = p2; 
        p2 = tmp;
    }

    showPlanet(p1);
    printf("‚Ì‚Ù‚¤‚ª");
    showPlanet(p2);
    puts("‚æ‚è‚à‘å‚«‚¢‚Å‚·B");

    return 0;
}