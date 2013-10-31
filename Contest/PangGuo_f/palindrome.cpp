#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt[26];
int element[110];

int GCD(int A,int B){
	int a = A>B?A:B;
	int b = A<B?A:B;	
	int r = 0;
	while( ( r = a%b ) != 0){
		a = b;
		b = r;
	}
	return b;
}

int palindrome(const string &s){
	for(int i =0  ; i < 26; i ++)
		cnt[i] = 0;
	for(int i = 0 ; i < s.length() ; i++){
		cnt[s[i]-'a'] ++;
	}
	int t = 0;
	for(int i = 0 ; i < 26; i ++)
		if((cnt[i] % 2) == 1)
			t++;
	if(t > 1)
		return 0;
	int elenum = s.length() / 2;
	for(int i = 0 ; i < elenum ; i ++){
		element[i] = i+1;
	}
	for(int i = 0 ; i < 26 ; i ++)
		if(cnt[i]){
			for(int j = 0 ; j < cnt[i]/2; j ++){
				int m = j+1;
				int k = elenum - 1;
				while((m>1)&&(k>=0)){
					int gcd = GCD(m,element[k]);
					m/=gcd;
					element[k]/=gcd;
					k--;
				}
			}
		}
	long long ans = 1;
	for(int i = 0 ; i < elenum ; i ++){
		ans = ans*element[i] % 1000000007;
		ans %= 1000000007;
	}
	return (int)ans;
}

//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{
/*
	cout << palindrome("aabb") << endl;
	cout << palindrome("ccccd") << endl;
	cout << palindrome("aammmmnn") << endl;
	cout << palindrome("b") << endl;
*/
	char s[110];
	while(scanf("%s",s)!=EOF){
		cout << palindrome(s) << endl;
	}
} 
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。                                               
