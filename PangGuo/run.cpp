#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int pos[110];

int run(const int *a,int n){
	int aa[110];
	for(int i = 1 ; i <= n	;i++)
		pos[i] = -1;
	for(int i = 0 ; i < n ; i ++){
		aa[i] = a[i];
		pos[aa[i]] = i;
	}
	int total = 0 ;
	for(int i = 0 ; i < n ; i ++){
		if(aa[i] == i+1)continue;
		total ++;
		aa[pos[i+1]] = aa[i];
		pos[aa[i]] = pos[i+1];
		aa[i] = i+1;
		pos[i+1] = i;	
	}
	return total;
}

//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{   
	int a[10] = {1,2,3};
	cout << run(a,3) << endl;
	int b[10] = {1,3,2,4,5};
	cout << run(b,3) << endl;
	int c[10] = {8,6,1,7,5,3,4,2};
	cout << run(c,8) << endl;
	int d[10] = {5,1,3,2,4};
	cout << run(d,5) << endl;
} 
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。                                               
