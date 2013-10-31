/*
ID: hanjiatong1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#define Max(a,b) ((a)>(b)?(a):(b))
#define S 101000

using namespace std;

char sign[3] = {"br"};

int main() {
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    int n ; 
    char s[S];
//	string s;
    
    //while (fin >> n)
    {
		fin >> n;
    fin >> s+1;
    
  //  fout << s+1 << endl;
    
    int first[2] , sfst = -1, last[2][2];
    
    for(int i=0;i<2;i++)
    {
    	last[i][0] = -1;
    	first[i] = n+1;
	}
    for(int i=0;i<2;i++)
    		last[i][1] = 0;
    // b 0;
    // r 1 ; 
    
    int ans = 0;
    
    for(int i = 1; i <= n ;i ++)
    {
		int cur = 0;
		if(s[i] == 'w')
			cur = 2;
		if(s[i] == 'r')
			cur = 1;
			
		if( sfst == -1 && cur != 2)
		{
			sfst = cur;
		}
		if(cur != 2 && first[cur] > n)
			first[cur] = i;
			
		if(cur != 2 && last[cur][0] == -1 && last[1-cur][0] != -1)
		{
			int tmp = i-1 - last[1-cur][1];
			if(tmp > ans)
				ans = tmp;
			last[1-cur][1] = last[1-cur][0];
			last[1-cur][0] = -1;
		}
		if(cur != 2)
			last[cur][0] = i;
	}
	if(sfst == -1)
		sfst = 0;
/*	fout << "fst: " << sfst << endl;
	fout << "first cur " << first[sfst] << endl;
	fout << "first 1-cur " << first[1-sfst] << endl;
	fout << ans << endl;*/
	int pos = n;
	int cnt = first[1-sfst] - 1;
	while(pos > first[1-sfst] && (s[pos] == sign[sfst]||s[pos] == 'w'))
	{
		cnt ++;
		pos --;
	}
	while(pos >= first[1-sfst] && (s[pos] == sign[1-sfst] || s[pos] == 'w'))
	{
		cnt ++;
		pos --;
	}
	
    ans = Max(ans,cnt);
    
    fout << ans << endl;
	}
    return 0;
}

/*
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb wwwbbrwrbrbrrbrbrwrwwrbwrwrrb
                       ****** *****
wwwbbrwrbrbrrbrbrwrwwrbwrwrr bwwwbbrwrbrbrrbrbrwrwwrbwrwrrb
                       ***** ******
29
wwwbbrwrbrbrrbrbrwrwwrbwrwrrb


*/
