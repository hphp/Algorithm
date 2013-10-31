#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int N, x, M;
long long mat[35][55][55];
long long Const[55][55];
long long vec[55];
long long tmp[55];
int main() {
   int i, j, k, l;
   while( scanf("%d%d%d", &N, &x, &M) > 0 )
   {
	   memset(mat, 0, sizeof(mat));
	   mat[0][0][0] = x % M;
	   mat[0][x + 1][0] = x % M;
	   for (i = 0; i < 55; i ++)
	      for (j = 0; j <= i; j ++)
		 if (j == 0 || j == i)
		    Const[i][j] = 1 % M;
		 else
		    Const[i][j] = (Const[i - 1][j] + Const[i - 1][j - 1]) % M;
	   for (i = 1; i <= x; i ++) {
	      mat[0][i][i] = x % M;
	      for (j = 0; j < i; j ++)
		 for (k = 0; k < x + 2; k ++) {
		    mat[0][k][i] += mat[0][k][j] * Const[i][j] * ((i - j) % 2 ? 1 : -1);
		    mat[0][k][i] %= M;
		    mat[0][k][i] += M;
		    mat[0][k][i] %= M;
		 }
	   }
	   mat[0][x + 1][x + 1] = 1 % M;
	   for (i = 0; (1LL << i + 1) <= N; i ++)
	      for (j = 0; j < x + 2; j ++)
		 for (k = 0; k < x + 2; k ++)
		    for (l = 0; l < x + 2; l ++) {
		       mat[i + 1][j][l] += mat[i][j][k] * mat[i][k][l];
		       mat[i + 1][j][l] %= M;
		    }
	   memset(vec, 0, sizeof(vec));
	   vec[x + 1] = 1 % M;
	   for (i = 0; (1LL << i) <= N; i ++)
	      if (N & (1LL << i)) {
		 memset(tmp, 0, sizeof(tmp));
		 for (j = 0; j < x + 2; j ++)
		    for (k = 0; k < x + 2; k ++) {
		       tmp[k] += vec[j] * mat[i][j][k];
		       tmp[k] %= M;
		    }
		 for (j = 0; j < x + 2; j ++)
		    vec[j] = tmp[j];
	      }
	   printf("%d\n", (int)vec[x]);
   }
   return 0;
}

