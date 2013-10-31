#include <cstdio>
#include <cstring>

const int MaxN = 505;

bool vis[15][5], success;
int n, top, deg[15], hash[MaxN];

struct E {
	int s, e;
}edge[MaxN][5];

void Input ()
{
	int i, j;
	char str[5][10];
	scanf ("%d", &n);
	getchar ();
	E tmp;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			gets (str[j]);		
		}
		tmp.s = hash[str[0][1]]; tmp.e = hash[str[2][1]];
		edge[i][0] = tmp;
		tmp.s = hash[str[1][0]]; tmp.e = hash[str[1][2]];
		edge[i][1] = tmp;
		tmp.s = hash[str[1][1]]; tmp.e = hash[str[1][3]];
		edge[i][2] = tmp;
	}
}

void DFS (int deep, int ch)
{
	int i, s, e;
	if (deep == n) {
		for (i = 1; i <= n; i++) {
			if (deg[i] != 2 + ch * 2) break;
		}
		if (i <= n) return ;
		if (ch == 0) DFS (0, 1);
		else success = true;
		return ;
	}
	for (i = 0; i < 3; i++) {
		if (vis[deep][i]) continue;
		s = edge[deep][i].s; e = edge[deep][i].e;
		if (deg[s] > 1  + ch * 2 || deg[e] > 1 + ch * 2) continue;
		vis[deep][i] = true;
		deg[s]++; deg[e]++;
		DFS (deep + 1, ch);
		if (success) return ;
		vis[deep][i] = false;
		deg[s]--; deg[e]--;
	}
}

int main ()
{
	int i, T, CS = 1;
	scanf ("%d", &T);
	for (i = 'A'; i <= 'J'; i++) hash[i] = i - 'A' + 1;
	while (T--) {
		Input ();
		success = false;
		memset (deg, 0, sizeof (deg));
		memset (vis, false, sizeof (vis));
		DFS (0, 0);
		printf ("Case #%d: ", CS++);
		if (success) {
			puts ("Yes");
		}
		else puts ("No");
	}
	return 0;
}

