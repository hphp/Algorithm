#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int cnt[26] = {0};

bool cmp(int a,int b){
    if(a <= b){
        return 0;
    }
    return 1;
}

int perfect(const string &s) {
    
    for(int i = 0 ; i < 26 ; i++){
        cnt[i] = 0;
    }
    for(int i = 0 ; i < s.length() ; i ++){
        if(s[i]>='a'&&s[i]<='z'){
            cnt[s[i]-'a']++;
        }
        else if(s[i]>='A' && s[i] <= 'Z' ){
            cnt[s[i]-'A']++;
        }
    }
    sort(cnt,cnt+26,cmp);
    /*
    for(int i = 0 ; i < 26; i++){
        printf("%d ",cnt[i]);
    }
    printf("\n");
    */
    int total = 0;
    int cur = 26;
    for(int i = 0 ; i < 26 ; i++){
        total += cur*cnt[i];
        cur--;
    }
    return total;
}


//start 提示：自动阅卷起始唯一标识，请勿删除或增加。
int main()
{   
    char s[100] = "daddy";
	int a = perfect(s);
	cout << a << endl;
    string ss = "dad";
	int b = perfect(ss);
	cout << b << endl;
} 
//end //提示：自动阅卷结束唯一标识，请勿删除或增加。                                               
