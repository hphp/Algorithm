#include <string>
using namespace std;

bool isP(string a)
{
	int s = 0;
	int e = a.length()-1;
	while(s <= e)
	{
		if(a[s]!=a[e])	
			break;
		s++;
		e--;
	}
	if(s > e)
		return 1;
	return 0;
}

class PalindromesCount
{
	public:
		int count(string a , string b)
		{
			int lena = a.length();
			int lenb = b.length();
			int ans = 0;
			for(int i=0;i<=lena;i++)
			{
				char c[110] = "";
				int j=0;
				int kk = 0;
				while(j < i)
					c[kk++] = a[j++];
				int k = 0;
				while(k < lenb)
					c[kk++] = b[k++];
				while(j < lena)
					c[kk++] = a[j++];
				c[kk++] = '\0';
				string cc = c;
				if(isP(cc))
					ans++;
			}
			return ans;
		}
};
