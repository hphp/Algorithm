/*
ID: hanjiatong1
PROG: namenum
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

#define N 5010

using namespace std;

string dic[N];

int Map[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1};
/*FILE * fw ;
fw = fopen("dict.txt","r");*/

int judge(char str[],string a)
{
	int i =0;
	int ss = strlen(str);
	int as = a.length();
	if(ss != as)return 0;
	for(;i<ss;i++)
	{
		if(Map[str[i]-'A'] + '0' != a[i])
		{
		//	fprintf(fw,"%d\n",Map[str[i]-'A']);
			break;
		}
	}
	if(i == ss)return 1;
	return 0;
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
    string a;
	char str[N];
    fin >> a ;
    FILE * pFile ;
    pFile = fopen("dict.txt","r");
    int cnt = 0;
    while(1)
    {
		if(fscanf(pFile,"%s",str) == EOF)
			break;
		if(judge(str,a))
		{
			cnt ++;
			fout << str << endl;
		}
	}
	if(cnt ==0)
 	   fout << "NONE" << endl;
    return 0;
}


/*
 FILE *dir= fopen("dict.txt", "r");

   int in = 0;
   while (1)
   {
       char str[100];
       if (fscanf(dir, "%s", str) == EOF)
           break;
       if (judge(str, s))
       {
           in = 1;
           printf("%s\n", str);
       }
   }

*/
