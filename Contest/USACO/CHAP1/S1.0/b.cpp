/*
ID: hanjiatong1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
//using namespace std;
#define S 101000

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    fin >> comet >> group;
    int sa = comet.length();
    int sb = group.length();
    int ans1 = 1;
    for(int i=0;i<sa;i++)
    {
		ans1 *= (comet[i]-'A'+1);
		ans1 %= 47;
	}
    int ans2 = 1;
    for(int i=0;i<sb;i++)
    {
		ans2 *= (group[i]-'A'+1);
		ans2 %= 47;
	}
	if(ans1 == ans2)
		fout << "GO" << endl;
	else fout << "STAY" << endl;
    return 0;
}
