/*
ID: hanjiatong1
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("kimbits.out");
    ifstream fin ("kimbits.in");
    int a, b;
    fin >> a >> b;
    fout << a+b << endl;
    return 0;
}
/*
����һ�� û��˼·
Ȼ��Ͳ����ˡ�
�����ϲ�����ʱ��һ���뵽�ˣ�
ͮͮ���ð�Ŷ�ǲ���
 
*/ 
