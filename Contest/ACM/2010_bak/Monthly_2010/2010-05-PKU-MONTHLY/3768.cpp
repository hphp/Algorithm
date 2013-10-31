
#include <stdio.h>
#include <math.h>
#define N 3010
#define K 6
#define P 9

int n;
char grid[N][N];
char ori[K][K];
int power[6][P];

void booling()
{
	for(int i=3;i<7;i++)
	{
		power[i][0] = 1;
		for(int j=1;j<P;j++)
			power[i][j] = power[i][j-1]*i;
	}	
}

void build(int sx,int sy,int size)
{
	int xx = sx;int yy = sy;
	if(size == 1)
	{
		for(int i=0;i<n;i++,xx++)
		{
			yy = sy;
			for(int j=0;j<n;j++,yy++)
			{
				grid[xx][yy] = ori[i][j];
			}
		}
		return;
	}
	int add = power[n][size-1];
	for(int i=0;i<n;i++,xx += add)
	{
		yy = sy;
		for(int j=0;j<n;j++,yy += add)
		{
			if(ori[i][j] != ' ')
			{
				build(xx,yy,size-1);
			}
		}
	}
}

int main()
{
	booling();
/*	freopen("3768.in","r",stdin);
	freopen("3768.out","w",stdout);*/
//	printf("%lf\n",log(3000.0)/log(3));
	while(scanf("%d",&n)!=EOF)
	{
		if(!n)break;
		getchar();
		for(int i=0;i<n;i++)
			gets(ori[i]);
		int size;
		scanf("%d",&size);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
				grid[i][j] = ' ';
			grid[i][power[n][size]] = '\0';
		}
		build(0,0,size);
/*		for(int i=0;i<power[n][size];i++)
			for(int j = N-2;j>=0;j--)
				if(grid[][])*/
		for(int i=0;i<power[n][size];i++)
			printf("%s\n",grid[i]);
	}
	return 0;
}
/*
3
# #
 # 
# #
1
3
# #
 # 
# #
3
4
 OO 
O  O
O  O
 OO 
2
0


# #
 # 
# #
# #   # #         # #   # #
 #     #           #     # 
# #   # #         # #   # #
   # #               # #   
    #                 #    
   # #               # #   
# #   # #         # #   # #
 #     #           #     # 
# #   # #         # #   # #
         # #   # #         
          #     #          
         # #   # #         
            # #            
             #             
            # #            
         # #   # #         
          #     #          
         # #   # #         
# #   # #         # #   # #
 #     #           #     # 
# #   # #         # #   # #
   # #               # #   
    #                 #    
   # #               # #   
# #   # #         # #   # #
 #     #           #     # 
# #   # #         # #   # #
     OO  OO     
    O  OO  O    
    O  OO  O    
     OO  OO     
 OO          OO 
O  O        O  O
O  O        O  O
 OO          OO 
 OO          OO 
O  O        O  O
O  O        O  O
 OO          OO 
     OO  OO     
    O  OO  O    
    O  OO  O    
     OO  OO     
*/
