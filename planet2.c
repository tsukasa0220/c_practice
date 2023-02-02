#include <stdio.h>

int main(void) {
    int no;
    do{
        printf("1‚©‚ç8‚Ì®”‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢:");
        scanf("%d",&no);
        switch(no){
            case 1:puts("‘¾—zŒn‘æ1˜f¯‚ÍA…¯‚Å‚·B"); break;
            case 2:puts("‘¾—zŒn‘æ2˜f¯‚ÍA‹à¯‚Å‚·B"); break;
            case 3:puts("‘¾—zŒn‘æ3˜f¯‚ÍA’n‹…‚Å‚·B"); break;
            case 4:puts("‘¾—zŒn‘æ4˜f¯‚ÍA‰Î¯‚Å‚·B"); break;
            case 5:puts("‘¾—zŒn‘æ5˜f¯‚ÍA–Ø¯‚Å‚·B"); break;
            case 6:puts("‘¾—zŒn‘æ6˜f¯‚ÍA“y¯‚Å‚·B"); break;
            case 7:puts("‘¾—zŒn‘æ7˜f¯‚ÍA“V‰¤¯‚Å‚·B"); break;
            case 8:puts("‘¾—zŒn‘æ8˜f¯‚ÍAŠC‰¤¯‚Å‚·B"); break;
        }
    }while (no<1||no>8);

    return 0;
}