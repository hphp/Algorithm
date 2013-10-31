/*
ID: hanjiatong1
PROG: test
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define N 510
#define F 1410
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))

using namespace std;

int main() {
    ofstream fout ("test.out");
    ifstream fin ("test.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}

