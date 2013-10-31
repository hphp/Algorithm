#define Min(a,b) ((a)<(b)?(a):(b))
#include <string>
using namespace std;

class GirlsAndBoys
{
	public:
		int sortThem(string s);
};

int GirlsAndBoys::sortThem(string s)
{
	int size = s.length();
	int count[2]={0},sum[2]={0};
	for(int i=0;i<size;i++)
	{
		if(s[i] == 'G')
		{
			sum[1] += count[0];
			count[1] ++;
		}
		if(s[i] == 'B')
		{
			sum[0] += count[1];
			count[0] ++;
		}
	}
	return Min(sum[0],sum[1]);
}
/*int main()
{
	char s[20];
	while(scanf("%s",s)!=EOF)
	{
		printf("%d\n",gab.sortThem(s));
	}
	return 0;
}*/
