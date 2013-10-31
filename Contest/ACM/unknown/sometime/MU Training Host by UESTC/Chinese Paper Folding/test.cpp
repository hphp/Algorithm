#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int cnt = 0;
    char st[128];
    while (cnt < 100){
          system("gen");
          system("folding");
          system("fold_sol");
          system("fc folding.out folding2.out > a.out");
          FILE *fin = fopen("a.out","r");
          fgets(st,128,fin);
          fgets(st,128,fin);
          if (st[0] == '*')
             break;
          printf("cnt = %d\n",cnt++);
    }
    printf("cnt = %d\n",cnt);
}
