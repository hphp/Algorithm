#include <stdio.h>
#include <string.h>
#define N 1010
int cur[N][3],pos[N][3];

void swap(int & a , int & b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	char s[20];
	int a,b,c;
	int X,Y,Z;
	while(scanf("%s",s)!=EOF)
	{
		if(strcmp(s,"FILL")==0)
		{
			scanf("%d%d%d",&X,&Y,&Z);
			printf("START\n");
			for(int i=0;i<X;i++)
				pos[i][0] = i,cur[i][0] = i;
			for(int i=0;i<Y;i++)
				pos[i][1] = i,cur[i][1] = i;
			for(int i=0;i<Z;i++)
				pos[i][2] = i,cur[i][2] = i;
		}
		else if(strcmp(s,"SWAP1") ==0)
		{
			scanf("%d%d",&a,&b);
			pos[cur[a][0]][0] = b;
			pos[cur[b][0]][0] = a;
			swap(cur[a][0],cur[b][0]);
		}
		else if(strcmp(s,"SWAP2") ==0)
		{
			scanf("%d%d",&a,&b);
			pos[cur[a][1]][1] = b;
			pos[cur[b][1]][1] = a;
			swap(cur[a][1],cur[b][1]);
		
		}
		else if(strcmp(s,"SWAP3") ==0)
		{
			scanf("%d%d",&a,&b);
			pos[cur[a][2]][2] = b;
			pos[cur[b][2]][2] = a;
			swap(cur[a][2],cur[b][2]);
		}
		else if(strcmp(s,"QUERY") ==0)
		{
			scanf("%d%d%d",&a,&b,&c);
			//printf("pos:%d %d %d\n",cur[a][0],cur[b][1],cur[c][2]);
			int ans = cur[a][0]*(Y*Z) + cur[b][1]*Z + cur[c][2]+1;
			printf("%d\n",ans);
		}
		else if(strcmp(s,"FIND")==0)
		{
			int cc;
			scanf("%d",&cc);
			cc--;
			c = cc%Z;
			cc/=Z;
			b = cc%Y;
			cc/=Y;
			a = cc;
			//printf("hei%d %d %d\n",a,b,c);
			if((a<X)&&(b<Y)&&(c<Z))
			printf("%d %d %d\n",pos[a][0],pos[b][1],pos[c][2]);
		}
	}
	return 0;
}
