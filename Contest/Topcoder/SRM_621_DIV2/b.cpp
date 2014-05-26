/*
2014-05-24
436.7 point
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#define N 2000000

bool if_exist[N] = {0};

using namespace std;
class NumbersChallenge{
	public:
	int MinNumber(vector<int> S){
        for(int i = 0 ; i < N ; i ++){
            if_exist[i] = 0;
        }
        int n = S.size();
        int max = 1<<n;
        for(int i = 1 ; i < max; i ++){
            int cur_sum = 0;
            for(int j = 0 ; j < n ; j ++){
                int jj = 1<<j; 
                if((i & jj)!=0){
                    cur_sum += S[j]; 
                }
            }
            if_exist[cur_sum] = 1;
        }
        int answer = 0;
        for(int i = 1; i < N ; i ++){
            if(if_exist[i]==0){
                answer = i;
                break;
            }
        }
        return answer;
	}
};
