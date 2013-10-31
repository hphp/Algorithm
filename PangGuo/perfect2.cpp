#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int cnt[26];

bool cmp(int a, int b){
    
    return a>b;
}

int perfect(const string &s) {
    for(int i = 0 ; i < 26 ; i ++)cnt[i]=0;

    for(int i = 0 ; i < s.length() ; i ++){
        
        if(s[i]>='a'&&s[i]<='z')cnt[s[i]-'a']++;
        if(s[i]>='A'&&s[i]<='Z')cnt[s[i]-'A']++;
    }
    sort(cnt,cnt+26,cmp);
    int total = 0;
    for(int i = 0 ; i < 26 ; i ++)
        total += cnt[i]*(26-i);
        return total;
}


//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{   
    cout << perfect("dad") << endl;
    cout << perfect("daddy") << endl;
} 
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。
