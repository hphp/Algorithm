#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

string stt = "ATGC";
string to = "TACG";

class DNAMatching
{
	private :
		string reverse(string a)
		{
			int len = a.length();
			string b;
			char bb[100];
			for(int i=0;i<len;i++)
			{
				for(int j=0;j<4;j++)
					if(a[i] == stt[j])
					{
						bb[len-1-i] = to[j];
				//		printf("hello%c",b[len-1-i]);
					}
			}
			bb[len] = '\0';
			b = bb;
		//	cout << b << endl;
			return b;
		}
	public :
		int getMaxSize(vector<string> dna)
		{
			int len = dna.size();
			int cnt = len;
			for(int i=0;i<len;i++)
			{
				string a = dna[i];
				string b = reverse(a);
			//	cout << b << endl;
				for(int j=i+1;j<len;j++)
					if(b == dna[j])
					{
						cnt--;	
					}
			}
			return cnt;
		}
};

/*int main()
{
	int n;
	string s;
	while(scanf("%d",&n)!=EOF)
	{DNAMatching dm = DNAMatching();
		vector <string> dna;
		for(int i=1;i<=n;i++)	
		{
			cin >> s;
			dna.push_back(s);	
		}
		printf("%d\n",dm.getMaxSize(dna));
	}
}
		
*/
