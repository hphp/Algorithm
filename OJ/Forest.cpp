#include <stdio.h>
#include <algorithm>
/*
	2013-10-24
	12:30 - 13:17
	ac for the first time , but maybe with too much codes.
*/
using namespace std;

int m_opn[101][101] = {0};

struct Opn{
	int id;
	int total;
	int arr[101];
}opn[101];

bool cmp(Opn a , Opn b){
	if(a.total > b.total){
		return 0;
	}
	else if(a.total < b.total)	{
		return 1;
	}
	else{
		for(int i = 0 ; i < a.total ; i ++){
			if(a.arr[i]<b.arr[i]){
				return 1;
			}
			else if(a.arr[i]>b.arr[i]){
				return 0;
			}
		}
		return 0;
	}
}

int main(){
	int t , p , a , b;
	scanf("%d%d",&t,&p);
	while(scanf("%d%d",&a,&b)!=EOF){
		m_opn[a][b] = 1;
	}
	for(int i = 1 ; i <= t ; i++ ){
		int cnt = 0;
		opn[i].id = i;
		opn[i].total = 0;
		for(int k = 1 ; k <= p ; k ++){
			if ( m_opn[i][k] == 1 ){
				opn[i].arr[opn[i].total++] = k;
			}
		}
	}
	std::sort(opn+1,opn+t+1,cmp);
/*
	for(int i = 1 ; i <= t; i++){
		printf("id:%d\n",opn[i].id);
		for(int k = 0 ; k < opn[i].total ; k ++){
			printf("%d ",opn[i].arr[k]);
		}
		printf("\n");
	}
*/
	int cnt = 1;
	for(int i = 2 ; i <= t ; i++){
		int flag = 0;
		if(opn[i].total != opn[i-1].total){
			flag = 1;
		}
		else{
			for(int j = 0 ; j < opn[i].total ; j ++){
				if(opn[i].arr[j]!=opn[i-1].arr[j]){
					flag = 1;
					break;
				}
			}
		}
		if(flag){
			cnt ++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
