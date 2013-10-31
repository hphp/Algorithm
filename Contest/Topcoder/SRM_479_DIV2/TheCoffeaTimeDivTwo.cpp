#include <vector>
#include <stdio.h>
#include <memory.h>
#define N 1010
using namespace std;

bool iftea[N];

class TheCoffeeTimeDivTwo
{
	public:
		int find(int n,vector<int> tea)
		{
			int size = tea.size();
			for(int i=0;i<=n;i++)
				iftea[i] = 0;
			for(int i=0;i<size;i++)
				iftea[tea[i]] = 1;
			int ctea = 0 , ccf= 0;
			int et = 0,ecf = 0;
			int time = 0;
			for(int i=n;i>0;i--)
			{
				if(iftea[i])
				{
					ctea ++;
					if(ctea == 1)
					{
						et = i;	
					}
					else if(ctea == 7)
					{
						time += (47 + et + ctea*4 + et);
						ctea = 0;
					}
				}
				else
				{
					ccf ++;
					if(ccf == 1)	
					{
						ecf = i;	
					}
					else if(ccf == 7)
					{
						time += (47+ecf + ccf*4 + ecf);
						ccf = 0 ;
					}
				}
			}
			if(ccf)
			{
				time += (47+ecf+ccf*4+ecf);
			}
			if(ctea)
			{
				time += (47+et+ctea*4+et);
			}
			return time;
		}
};
/*
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		vector <int> r;
		r.clear();
		int a;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&a);
			r.push_back(a);
		}
		TheCoffeeTimeDivTwo ct = TheCoffeeTimeDivTwo();
		printf("%d\n",ct.find(n,r));
	}
}*/
