/*
ID: hanjiatong1
PROG: checker
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define N 20

using namespace std;

int n;
int ocp[N*2][2];
int ocpc[N];
int cnt;
int rr[N],rc;

ofstream fout ("checker.out");
ifstream fin ("checker.in");

int dfs(int r)
{
	if(r > n)
	{
		if(cnt < 3)
		{
			for(int i=1;i<n;i++)
			{
				fout << rr[i] << ' ';
			}
			fout << rr[n] << endl;
		}
		cnt ++;
		return 1;
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		if(ocpc[i] == 0)
		{
			if(ocp[r+i][0] == 0 && ocp[r-i+n-1][1] == 0)
			{
				ocp[r+i][0]	 = 1;
				ocp[r-i+n-1][1] = 1;
				ocpc[i] = 1;
				rr[rc++] = i;
				ans += dfs(r+1);
				rc--;
				ocp[r+i][0]	 = 0;
				ocp[r-i+n-1][1] = 0;
				ocpc[i] = 0;
			}
		}
	}
	return ans;
}

int main() {
    fin >> n;
    rc = 1;
    cnt = 0;
    int r = 1;
    int ans = 0;
    int left = n;
    for(int i=1;i<=n/2;i++)
    {
		ocp[r+i][0]	 = 1;
		ocp[r-i+n-1][1] = 1;
		ocpc[i] = 1;
		rr[rc++] = i;
		int tmp = dfs(r+1);
		ans += tmp*2;
		rc--;
		ocp[r+i][0]	 = 0;
		ocp[r-i+n-1][1] = 0;
		ocpc[i] = 0;
		left = i;
	}
	if(n%2==1)
	{
		int i = n/2+1;
		ocp[r+i][0]	 = 1;
		ocp[r-i+n-1][1] = 1;
		ocpc[i] = 1;
		rr[rc++] = i;
		int tmp = dfs(r+1);
		ans += tmp;
		rc--;
		ocp[r+i][0]	 = 0;
		ocp[r-i+n-1][1] = 0;
		ocpc[i] = 0;	
		left = i;
	}
	if(cnt < 3)
	{
		for(int i=left+1;cnt<3;i++)
		{
			ocp[r+i][0]	 = 1;
			ocp[r-i+n-1][1] = 1;
			ocpc[i] = 1;
			rr[rc++] = i;
			dfs(r+1);
			rc--;
			ocp[r+i][0]	 = 0;
			ocp[r-i+n-1][1] = 0;
			ocpc[i] = 0;
			left = i;	
		}
	}
/*    while(1)
    {
		while(r <= n)
		{
			for(int i=1;i<=n;i++)
			{
				if(ocpc[i] == 0)
				{
					if(ocp[r+i][0] == 0 && ocp[r-i+n-1][1] == 0)
					{
						ocp[r+i][0]	 = 1;
						ocp[r-i+n-1][1] = 1;
						ocpc[i] = 1;
						rr[rc++] = i;
						r++;
					}
				}
			}	
		}
		if(cnt < 3)
		{
			for(int i=1;i<n;i++)
			{
				fout << rr[i] << ' ';
			}
			fout << rr[n] << endl;
		}
		cnt ++;
		rc--;
		ocp[r+i][0]	 = 0;
		ocp[r-i+n-1][1] = 0;
		ocpc[i] = 0;
		r--;
	}*/
    fout << ans << endl;
    return 0;
}

/*
2010-06-09-15:12--16:02
        Column
    1   2   3   4   5   6
  -------------------------
1 |   | O |   |   |   |   |
  -------------------------
2 |   |   |   | O |   |   |
  -------------------------
3 |   |   |   |   |   | O |
  -------------------------
4 | O |   |   |   |   |   |
  -------------------------
5 |   |   | O |   |   |   |
  -------------------------
6 |   |   |   |   | O |   |
  -------------------------
*/
