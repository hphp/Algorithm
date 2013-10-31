#include <stdio.h>
#include <string.h>
struct abc{
    char c[60], l;
}a[20];
int l[50000], w, r;
char s[50000][610], str[610];
int dis[20][20];
int u[50000];
int main(){
    int n, i, j, k, t, x, y, ri = 1;
//    freopen("123.in", "r", stdin);
//    freopen("123.out", "w", stdout);
    while (scanf("%d", &n) != EOF){
        gets(a[0].c);
        for (i = 0; i < n; i++){
            gets(a[i].c);
            a[i].l = strlen(a[i].c);
        }
        for (i = 0; i < n; i++){
            u[i] = 1;
        }
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (i != j && u[j] && strstr(a[j].c, a[i].c) != NULL){
                    u[i] = 0;
                }
            }
        }
        j = 0;
        for (i = 0; i < n; i++){
            if (u[i]){
                a[j] = a[i];
                j++;
            }
        }
        n = j;
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                for (k = 0; a[i].c[k]; k++){
                    for (t = 0; a[i].c[k + t]; t++){
                        if (a[i].c[k + t] != a[j].c[t]){
                            break;
                        }
                    }
                    if (a[i].c[k + t] == 0){
                        break;
                    }
                }
                dis[i][j] = a[j].l - t;
            }
        }
        for (i = 0; i < (1<<n) * n; i++){
            u[i] = 0;
        }
        for (i = 0; i < n; i++){
            l[i] = (1<<i) * n + i;
            u[l[i]] = a[i].l;
            strcpy(s[l[i]], a[i].c);
        }
        r = 0;
        w = n;
        while (r < w){
            x = l[r] / n;
            y = l[r] % n;
            for (i = 0; i < n; i++){
                if ((x & (1<<i)) == 0){
                    if (u[(x | (1<<i)) * n + i] == 0){
                        strcpy(str, s[l[r]]);
                        strcat(str, a[i].c + a[i].l - dis[y][i]);
                        l[w] = (x | (1<<i)) * n + i;
                        u[(x | (1<<i)) * n + i] = u[l[r]] + dis[y][i];
                        strcpy(s[l[w]], str);
                        w++;
                    }
                    else{
                        if (u[(x | (1<<i)) * n + i] > u[l[r]] + dis[y][i]){
                            strcpy(str, s[l[r]]);
                            strcat(str, a[i].c + a[i].l - dis[y][i]);
                            u[(x | (1<<i)) * n + i] = u[l[r]] + dis[y][i];
                            strcpy(s[(x | (1<<i)) * n + i], str);
                        }
                        else if (u[(x | (1<<i)) * n + i] == u[l[r]] + dis[y][i]){
                            strcpy(str, s[l[r]]);
                            strcat(str, a[i].c + a[i].l - dis[y][i]);
                            if (strcmp(str, s[(x | (1<<i)) * n + i]) < 0){
                                strcpy(s[(x | (1<<i)) * n + i], str);
                            }
                        }
                    }
                }
            }
            r++;
        }
        x = 1<<30;
        y = (1<<n) - 1;
        for (i = 0; i < n; i++){
            if (u[y * n + i] < x || (u[y * n + i] == x && strcmp(s[y * n + i], str) < 0)){
                x = u[y * n + i];
                u[y * n + i] = 0;
                strcpy(str, s[y * n + i]);
            }
        }
        printf("Case #%d: %s\n", ri++, str);
    }
    return 0;
}
