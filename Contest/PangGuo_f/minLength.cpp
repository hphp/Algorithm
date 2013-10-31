#include <cstdio>
#include <string.h>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define N 202
#define MAX 2020
int ife[N][N][3];
int minlen[N][N];

#define Min(a,b) ((a)<(b)?(a):(b))

int minLength(const char *s){
//	cout << s << endl;
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < N ; j ++){
			for(int k = 0 ; k < 3 ; k ++)
				ife[i][j][k] = 0;
			minlen[i][j] = MAX;
		}
	int len = strlen(s);
	for(int i = 0 ; i < len; i ++)
		ife[i][i][s[i]-'a'] = 1;
	for(int i = 1 ; i < len ; i ++){ // this is the length of some period;
		for(int start = 0 ; start < len - i ; start ++){
			for(int point = 0 ; point < i ; point ++){
				for(int k = 0 ; k < 3 ; k ++){
					if ( ife[start][start+point][k] ){
						for(int ss = 0 ; ss < 3 ; ss ++)
							if(ss != k && ife[start+point+1][start+i][ss]){
								ife[start][start+i][3-k-ss] = 1;
							}
					}
				}
			}
		}
	}
	for(int i = 0 ; i < len ; i ++)
		for(int j =0  ; j < len ; j ++)
			for(int k = 0 ; k < 3 ; k ++)
				if(ife[i][j][k])
					minlen[i][j] = 1;
	for(int i = 1 ; i < len ; i ++)
		for(int start = 0 ; start < len - i + 1 ; start ++)
			for(int point = 0 ; point < i ; point ++)
				minlen[start][start+i] = Min(minlen[start][start+point] + minlen[start+point+1][start+i], minlen[start][start+i]);

	return minlen[0][len-1];
}

//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{
	cout << minLength("cab") << endl;
	cout << minLength("bcab") << endl;
	cout << minLength("cacacaca") << endl;
	cout << minLength("cccc") << endl;
/*	char s[1000];
	while(scanf("%s",s)!=EOF){
		cout << minLength(s) << endl;
	}
*/
} 
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。                                               
