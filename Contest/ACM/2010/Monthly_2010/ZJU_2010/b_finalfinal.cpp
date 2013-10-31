//2010-4-11-15:00-17:25 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 340
#define L 53
#define avl(x,y) ((((x)>=1)&&((x)<=n)&&((y)>=0)&&((y)<m))?1:0)

char arr[52][7][18] = 
{
	{
{"111111MMM1111111"},
{"11111MM1MM111111"},
{"1111MM111MM11111"},
{"111MMMMMMMMM1111"},
{"11MM1111111MM111"},
{"1MMM11111111MM11"},
{"1MM1111111111MM1"}

	},

	{
{"1MMMMMMMMMMM1111"},
{"1MM11111111MM111"},
{"1MM11111111MM111"},
{"1MMMMMMMMMMM1111"},
{"1MM11111111MM111"},
{"1MM11111111MM111"},
{"1MMMMMMMMMMM1111"}

	},

	{
{"11111MMMMMMMM111"},
{"111MM1111111MM11"},
{"11MM111111111MM1"},
{"11MM111111111111"},
{"11MM111111111MM1"},
{"111MM1111111MM11"},
{"11111MMMMMMMM111"}

	},

	{
{"1MMMMMMMMMMM1111"},
{"1MM111111111MM11"},
{"1MM1111111111MM1"},
{"1MM1111111111MM1"},
{"1MM1111111111MM1"},
{"1MM111111111MM11"},
{"1MMMMMMMMMMM1111"}

	},

	{
{"1MMMMMMMMMMMM111"},
{"1MM1111111111111"},
{"1MM1111111111111"},
{"1MMMMMMMMMMMM111"},
{"1MM1111111111111"},
{"1MM1111111111111"},
{"1MMMMMMMMMMMM111"}

	},

	{
{"1MMMMMMMMMMMMM11"},
{"1MM1111111111111"},
{"1MM1111111111111"},
{"1MMMMMMMMMMMMM11"},
{"1MM1111111111111"},
{"1MM1111111111111"},
{"1MM1111111111111"}

	},

	{
{"11111MMMMMMMM111"},
{"111MM1111111MM11"},
{"11MM111111111MM1"},
{"11MM111111111111"},
{"11MM111111MMMMM1"},
{"111MM1111111MM11"},
{"11111MMMMMMMMM11"}

	},

	{
{"1MM111111111MM11"},
{"1MM111111111MM11"},
{"1MM111111111MM11"},
{"1MMMMMMMMMMMMM11"},
{"1MM111111111MM11"},
{"1MM111111111MM11"},
{"1MM111111111MM11"}

	},

	{
{"11111MMMMMM11111"},
{"1111111MM1111111"},
{"1111111MM1111111"},
{"1111111MM1111111"},
{"1111111MM1111111"},
{"1111111MM1111111"},
{"11111MMMMMM11111"}

	},

	{
{"1111MMMMMMMM1111"},
{"1111111MM1111111"},
{"1111111MM1111111"},
{"1111111MM1111111"},
{"111MM11MM1111111"},
{"111MMM1MM1111111"},
{"11111MMMM1111111"}

	},

	{
{"11MM111111MMM111"},
{"11MM11111MMM1111"},
{"11MM111MMM111111"},
{"11MMMMM111111111"},
{"11MM111MMM111111"},
{"11MM11111MMM1111"},
{"11MM111111MMMM11"}

	},

	{
{"11MM111111111111"},
{"11MM111111111111"},
{"11MM111111111111"},
{"11MM111111111111"},
{"11MM111111111111"},
{"11MM111111111111"},
{"11MMMMMMMMMMMM11"}

	},

	{
{"1MM1111111111MM1"},
{"1MMMM111111MMMM1"},
{"1MM1MM1111MM1MM1"},
{"1MM11MMMMM111MM1"},
{"1MM1111M11111MM1"},
{"1MM1111111111MM1"},
{"1MM1111111111MM1"}

	},

	{
{"1MMM111111111MM1"},
{"1MMMM11111111MM1"},
{"1MM1MM1111111MM1"},
{"1MM11MM111111MM1"},
{"1MM1111MM1111MM1"},
{"1MM111111MMM1MM1"},
{"1MM11111111MMMM1"}

	},

	{
{"11111MMMMMM11111"},
{"111MMM1111MMM111"},
{"11MMM111111MMM11"},
{"1MM1111111111MM1"},
{"11MMM111111MMM11"},
{"111MMM1111MMM111"},
{"11111MMMMMM11111"}

	},

	{
{"1MMMMMMMMMMM1111"},
{"1MM111111111MM11"},
{"1MM1111111111MM1"},
{"1MM111111111MM11"},
{"1MMMMMMMMMMM1111"},
{"1MM1111111111111"},
{"1MM1111111111111"}

	},

	{
{"11111MMMMMM11111"},
{"111MMM1111MMM111"},
{"11MMM111111MMM11"},
{"1MM1111111111MM1"},
{"11MMM1MMMM1MMM11"},
{"111MMM11MMMMM111"},
{"111111MMMM1MMMM1"}

	},

	{
{"1MMMMMMMMMMM1111"},
{"1MM111111111MM11"},
{"1MM1111111111MM1"},
{"1MM111111111MM11"},
{"1MMMMMMMMMMM1111"},
{"1MM11111111MM111"},
{"1MM111111111MMM1"}

	},

	{
{"1111MMMMMMMM1111"},
{"111MM1111111MM11"},
{"11MMM1111111MMM1"},
{"1111MMMMM1111111"},
{"1MMM111MMMM11111"},
{"111MMM11111MMM11"},
{"11111MMMMMMM1111"}

	},

	{
{"11MMMMMMMMMMMM11"},
{"11MMMMMMMMMMMM11"},
{"1111111MM1111111"},
{"1111111MM1111111"},
{"1111111MM1111111"},
{"1111111MM1111111"},
{"1111111MM1111111"}

	},

	{
{"1MM1111111111MM1"},
{"1MM1111111111MM1"},
{"1MM1111111111MM1"},
{"1MM1111111111MM1"},
{"1MMM11111111MMM1"},
{"1MMM11111111MMM1"},
{"111MMMMMMMMMM111"}

	},

	{
{"1MMMM111111MMMM1"},
{"11MMM111111MMM11"},
{"11MMM111111MMM11"},
{"111MMM1111MMM111"},
{"1111MMM11MMM1111"},
{"11111MM11MM11111"},
{"111111MMMM111111"}

	},

	{
{"1MM1111111111MM1"},
{"1MM1111111111MM1"},
{"11MM111MM111MM11"},
{"11MM111MM111MM11"},
{"11MM111MM111MM11"},
{"11MM1MM11MM1MM11"},
{"111MMM1111MMM111"}

	},

	{
{"11MMM111111MMM11"},
{"111MMM1111MMM111"},
{"1111MMM11MMM1111"},
{"111111MMMM111111"},
{"1111MMM11MMM1111"},
{"111MMM1111MMM111"},
{"11MMM111111MMM11"}

	},

	{
{"11MMM111111MMM11"},
{"111MMM1111MMM111"},
{"1111MMM11MMM1111"},
{"111111MMMM111111"},
{"1111111MM1111111"},
{"1111111MM1111111"},
{"1111111MM1111111"}

	},

	{
{"111MMMMMMMMMM111"},
{"1111111111MM1111"},
{"111111111MM11111"},
{"11111111MM111111"},
{"111111MM11111111"},
{"11111MM111111111"},
{"111MMMMMMMMMMM11"}

	}

};



int mv[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

char s[N][N];
int asxx[L];
int asyy[L];
int aexx[L];
int aeyy[L];
int n,m;
int sign[L];


struct Que
{
	int x,y;
}queue[N*N];
int cnt[N][N];

int bfs(int sx,int sy)
{
	int head = 0;
	int tail = 1;
	queue[0].x = sx;
	queue[0].y = sy;
	int check[N][N] = {0};
	while(head < tail)
	{
		int ssx = queue[head].x;
		int ssy = queue[head].y;
		check[ssx][ssy] = 1;
		for(int k=0;k<8;k++)
		{
			int xx = ssx + mv[k][0];
			int yy = ssy + mv[k][1];
			if(xx>=1&&xx<=n&&yy>=0&&yy<m)
			{
				if(s[xx][yy] == 'M')
				if(check[xx][yy] == 0)
				{
//					printf("%d %d %c\n",xx,yy,s[xx][yy]);
//					system("pause");
					check[xx][yy] = 1;
					queue[tail].x = xx;
					queue[tail].y = yy;
					tail++;
				}
			}
		}
		head ++ ;
	}
	for(int i=0;i<head;i++)
	{
		int x= queue[i].x;
		int y= queue[i].y;
		cnt[x][y] = head;	
	}
	return head;
}

int count[L];

int main()
{
//	freopen("b_later.out","r",stdin);
//	freopen("b_later.show","w",stdout);
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<7;j++)
			for(int k=0;k<16;k++)
			{
				arr[i+26][j][k] = arr[i][6-j][15-k];
			}
	}
/*	for(int i=0;i<52;i++)
	{
		printf("7 16\n");
		for(int j=0;j<7;j++)
			printf("%s\n",arr[i][j]);
		printf("\n");
	}*/
	for(int i=0;i<52;i++)
	{
		count[i] = 0;
		asxx[i] = 7;
		asyy[i] = 15;
		aexx[i] = 0;
		aeyy[i] = 0;
		for(int j=0;j<7;j++)
		{
			for(int k=0;k<16;k++)
			{
				if(arr[i][j][k] == 'M')
				{
					count[i]++;
					if(asxx[i] > j)
						asxx[i] = j;
					if(asyy[i] > k)
						asyy[i] = k;
					if(aexx[i] < j)
						aexx[i] = j;
					if(aeyy[i] < k)
						aeyy[i] = k;
				}
			}
		}
	}
	for(int i=0;i<52;i++)
	{
		aeyy[i]++;
		aexx[i]++;
	//	printf("%d %d %d %d\n",asxx[i],asyy[i],aexx[i],aeyy[i]);
	}
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(int i=0;i<L;i++)
			sign[i] = 0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]);
			for(int j=0;j<m;j++)
				cnt[i][j] = 0;
		}
		for(int k=0;k<52;k++)
		{
			if(k>25&&sign[k-26]==1)
				continue;
			int sizex = 6;
			int sizey = aeyy[k]-asyy[k];
			int endx = n-6;
			int endy = m-sizey;
			for(int i=1;i<=endx;i++)
			{
				for(int j=0;j<=endy;j++)
				{
						int sx = i;
						int sy = j;
						int asx = asxx[k];
						int asy = asyy[k];
						int flag = 0;
						for( sx=i,asx=asxx[k];sx<=n&&asx<aexx[k];sx++,asx++)
						{
							for( sy=j,asy=asyy[k];sy<m&&asy<aeyy[k];sy++,asy++)
							{
								if(arr[k][asx][asy] != s[sx][sy])
								{
									if(s[sx][sy] == 'M')
									{
								/*		int kk=0;
										for(;kk<8;kk++)
										{
											int sxx = sx + mv[kk][0];
											int syy = sy + mv[kk][1];
											if(avl(sxx,syy) && s[sxx][syy] == 'M')
											{
												break;	
											}
										}
										if(kk < 8)
										{
											flag =1 ;
											break;	
										}*/
									}
									else 
									{
										flag =1 ;
										break;
									}
								}
								else
								{
								if(s[sx][sy] == 'M' && cnt[sx][sy] == 0)
								{
									cnt[sx][sy] = bfs(sx,sy);
								//	if(k == 6)
								//		printf("%d %d\n",cnt[sx][sy],count[k]);
									if(cnt[sx][sy] != count[k])
									{
										flag = 1;break;	
									}
								}
								if(s[sx][sy] == 'M' && cnt[sx][sy]!=0)
								{
									if(cnt[sx][sy] != count[k])
									{
										/*if(k == 11)
											printf("%d %d %d\n",sx,sy,cnt[sx][sy]);*/
										flag = 1;break;	
									}	
								}	
								}
							//	if(i == 1 && j == 2&&k==6)
							//		printf("%d %d %d %c\n",k,asx,asy,arr[k][asx][asy]);
/*								if(arr[k][asx][asy]=='M')
								{
									if(s[sx][sy]== 'M');
									else
									{
						//				if(i == 1 && j == 2&&k==6)
						//				printf(" error here :%d %d %d %d\n",sx,sy,asx,asy);
										flag = 1;break;	
									}
								}*/
							}
							if(flag == 1)
								break;
						}
						if(asx < aexx[k] || asy < aeyy[k])
						{
							flag = 1;
						}
						if(flag == 0)
						{
							sign[k] = 1;
							break;
						}
				}
				if(sign[k] == 1)
					break;
			}
			if(sign[k] == 1)
			{
				if(k>25)
				{
					sign[k-26] = 1;
				}
			}
		}
		for(int i=0;i<26;i++)
			if(sign[i]==1)
				printf("%c",i+'A');
		printf("\n");
	}
	return 0;
}
/*
15 19
11111MMMMMMMM111111
111MM1111111MM11111
11MM111111111MM1111
11MM111111111111111
11MM111111MMMMM1111
111MM1111111MM11111
11111MMMMMMMMM11111
1111111111111111111
1111MMM111111111MM1
1111MMMM11111111MM1
1111MM1MM1111111MM1
1111MM11MM111111MM1
1111MM1111MM1111MM1
1111MM111111MMM1MM1
1111MM11111111MMMM1

7 18
1111MMM111111111MM
1111MMMM11111111MM
1111MM1MM1111111MM
1111MM11MM111111MM
1111MM1111MM1111MM
1111MM111111MMM1MM
1111MM11111111MMMM

9 14
11111MMMMMM111
1111111MM11111
1MM1111MM11111
1MM1111MM11111
1MM1111MM11111
1MM1111MM11111
1MM11MMMMMM111
1MM11111111111
1MMMMMMMMMMMM1

*/

