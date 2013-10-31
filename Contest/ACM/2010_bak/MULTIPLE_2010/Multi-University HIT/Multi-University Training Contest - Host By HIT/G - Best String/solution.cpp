#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


char ch[300];
vector<int> ans;
int cal(int v[], int start)
{
    int now = 0;
    int h[100], temp = 0;
    for (int i = 0; i < 62; i++)   h[i] = v[i];
    while (1)
    {
        int tf = 0;
        for (int i = 0; i < 62; i++)
        {
            if (h[i] == 0)  continue;
            int kk = v[i] - h[i];
            if (i == start)
            {
                if (now - kk - kk > 0)
                {
                    h[i]--;
                    temp++;
                    tf = 1;
                    now++;
                }
            }
            else
            {
                if (now + 1 - kk - kk > 0)
                {
                    h[i]--;
                    now++;
                    temp++;
                    tf = 1;
                }
            }
        }
        if (tf == 0)  break;
    }
    return temp;
}
void bestString(int v[])
{
    int kk = cal(v, -1);
    int start = -1;
    for (int i = kk-1, j; i >= 0; i--)
    {
       // cout << i << endl;
        for (j = 62; j >= 0; j--)
        {
            if (v[j] == 0||start == j)  continue;
            v[j]--;
            if (cal(v, j) == i)
            {
                break;
            }
            v[j]++;
        }
        start = j;
        ans.push_back(j);
    }
}

char s[1000+5];
int f[256], v[100];

int T;
int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    for (int i = '0'; i <= '9'; i++)   f[i] = i - '0';
    for (int i = 0; i < 62; i++)
    {
        if (i < 10)   ch[i] = '0' + i;
        else if (i < 36)  ch[i] = 'A' + i - 10;
        else     ch[i] = 'a' + i - 36;
    }
    for (int i = 'a'; i <= 'z'; i++)   f[i] = i - 'a' + 36;
    for (int i = 'A'; i <= 'Z'; i++)   f[i] = i - 'A' + 10;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        cout << s << endl;
        int n = strlen(s);
        memset(v, 0, sizeof(v));
        ans.clear();
        for (int i = 0; i < n; i++)
        {
            v[f[s[i]]]++;
        }
        bestString(v);
        for (int i = 0; i < ans.size(); i++)
        {
            printf("%c", ch[ans[i]]);
        }
        printf("\n");
    }
};
