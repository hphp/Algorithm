/*
ID: hanjiatong1
PROG: ratios
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#define N 5
#define avl(t) ((t)==0?0:1)
using namespace std;
ifstream fin("ratios.in");
ofstream fout("ratios.out");

int v[N][N];

int main() {
    
    for(int i=0;i<4;i++)
    	for(int j=0;j<3;j++)
	    	fin >> v[i][j];

	int ii,jj,kk,ff;
	bool flag = 0;
	for(int sum = 1 ;sum <= 300 ; sum ++)
	{
		for(int i=0;i<=100;i++)
		{
			for(int j=0;j<=100&&sum-i-j>=0;j++)
			{
				int k = sum - i - j;	
				if(k > 100)continue;
				int t[3];
				t[0] = v[1][0]*i + v[2][0]*j + v[3][0]*k;
				t[1] = v[1][1]*i + v[2][1]*j + v[3][1]*k;
				t[2] = v[1][2]*i + v[2][2]*j + v[3][2]*k;
				int fff = -1;
				int m = 0;
				for(;m<3;m++)
				{
					if(t[m] == 0 && v[0][m] == 0)
						continue;
					else if(v[0][m] == 0 )
						break;
					if(t[m]%v[0][m] ==0 && (fff == -1 || t[m]/v[0][m] == fff))
					{
						fff = t[m]/v[0][m];
					}
					else break;
				}
				if(m == 3)
				{
					ii = i;
					jj = j;
					kk = k;
					ff = fff;
					flag = 1;break;	
				}
	/*
				if(((!avl(v[0][0])&&a==0)|| a % v[0][0] == 0) &&((!avl(v[0][1])&&b==0)||  b % v[0][1] == 0) && ((!avl(v[0][2])&&c==0)|| c%v[0][2] == 0) && (!avl(v[0][0])||!avl(v[0][1])||a / v[0][0] == b / v[0][1]) && (!avl(v[0][2])||!avl(v[0][1])||b / v[0][1] == c/v[0][2]))
				{
					ii = i;
					jj = j;
					kk = k;
					ff = a/v[0][0];
					flag = 1;
					break;	
				}
	*/
			}
			if(flag == 1)break;
		}
		if(flag == 1)break;
	}
	if(flag == 0)
		fout << "NONE" << endl;
	else
		fout << ii << " " << jj << " " << kk << " "  << ff << endl;
    return 0;
}
/*
2010-09-10
09:49-10:19
����Ƚ�����
���˱ȽϾ�
��˿��˺�������۲��֡� 

30���ӣ���������Ϊ��Щ��ı�����ʵ��ֵҪ�������⡣
����ٴν����ʱ��úõĿ���һ�����⣬Ҳ����һ�¡�
2�γɹ�
��ȡ�Ժ� һ��AC
����ii , jj , kk , ��ii + jj + kk == sum
������ii1 + jj1 + kk1 == sum���Һ���ʽ���ȵĻ���
��ô�� Ӧ���ǲ����ڵġ�
���ǲ�̫��֤������


���˱�ƣ������ж��Ƿ�Ϊ0�ĵط����˼�ֱ���õĳ˷���cool
����һ��Ҫ��fscanf
 
 
*/
