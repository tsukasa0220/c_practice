#include <stdio.h>

int main(void) {
    int no;
    printf("‚P‚©‚ç‚W‚Ü‚Å‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢:"); scanf("%d",&no);

    switch (no){
    case 1:puts("‘¾—zŒn‘æ‚P˜f¯‚ÍA…¯‚Å‚·B"); break;
    case 2:puts("‘¾—zŒn‘æ‚Q˜f¯‚ÍA‹à¯‚Å‚·B"); break;
    case 3:puts("‘¾—zŒn‘æ‚R˜f¯‚ÍA’n‹…‚Å‚·B"); break;
    case 4:puts("‘¾—zŒn‘æ‚S˜f¯‚ÍA‰Î¯‚Å‚·B"); break;
    case 5:puts("‘¾—zŒn‘æ‚T˜f¯‚ÍA–Ø¯‚Å‚·B"); break;
    case 6:puts("‘¾—zŒn‘æ‚U˜f¯‚ÍA“y¯‚Å‚·B"); break;
    case 7:puts("‘¾—zŒn‘æ‚V˜f¯‚ÍA“V‰¤¯‚Å‚·B"); break;
    case 8:puts("‘¾—zŒn‘æ‚W˜f¯‚ÍAŠC‰¤¯‚Å‚·B"); break;
    default :printf("‘¾—zŒn‘æ%d˜f¯‚ÍA’m‚ç‚ê‚Ä‚¢‚Ü‚¹‚ñB\n",no); break;
    }
    
    return 0;
}