#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 210000
char str[120];
int sum[MAXN],n;
int arr[MAXN],crr[MAXN];
struct NODE{
	int v,x,y;	
}brr[MAXN];
int BSearch(int x,int high){
	int left=0,right=high,mid;
	while(left<right){
		mid=(left+right)>>1;
		if(crr[mid]>=x)right=mid;
		else left=mid+1;	
	}
	return right;	
}
int LowBit(int x){
	return x&(-x);	
}
bool Updata(int x,int high){
	int now=x;
	while(now<=high){
		sum[now]+=1;
		now+=LowBit(now);	
	}
	return true;	
}
int Sum(int x){
	int now=x,res_ans=0;
	while(now>0){
		res_ans+=sum[now];
		now-=LowBit(now);	
	}	
	return res_ans;
}
int main(){
	while(scanf("%d",&n)!=EOF){
		int cnt=0,ncnt=1;
		for(int i=0;i<n;i++){
			scanf("%s",str);
			if(str[0]=='I'){
				brr[i].v=0;
				scanf("%d",&brr[i].x);
				arr[cnt++]=brr[i].x;
			}
			else{
				brr[i].v=1;
				scanf("%d %d",&brr[i].x,&brr[i].y);	
				arr[cnt++]=brr[i].x;arr[cnt++]=brr[i].y;
			}	
		}
		memset(sum,0,sizeof(sum));
		sort(arr,arr+cnt);
		crr[0]=arr[0];
		for(int i=1;i<cnt;i++)
			if(arr[i]!=arr[i-1])crr[ncnt++]=arr[i];	
		for(int i=0;i<n;i++)
			if(brr[i].v){
				int x=BSearch(brr[i].x,ncnt);
				int y=BSearch(brr[i].y,ncnt);
				//printf("%d---%d\n",x,y);
				int ans_sum=Sum(y+1)-Sum(x);
				printf("%d\n",ans_sum);
			}
			else {
				int x=BSearch(brr[i].x,ncnt);
				Updata(x+1,ncnt);	
			}
	}
}

