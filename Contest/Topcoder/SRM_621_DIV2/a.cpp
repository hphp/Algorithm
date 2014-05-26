#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;
class TwoWaysSorting{
	public:
	string sortingMethod(vector<string> l_list){
		int len = l_list.size();
		int last_len = 0;
		int sign = 0;
        int i = 0;
		for(i = 0 ; i < len ; i ++){
			string ele = l_list[i];
			if(ele.length() < last_len){
				break;
			}
			last_len = ele.length();
		}
        if(i == len){
            sign = sign | 1; 
        }
        for(i = 1; i < len; i ++){
            if(l_list[i] < l_list[i-1]){
                break;
            }
        }
        if(i == len){
            sign = sign | 2;
        }
        string r = "";
        if(sign == 0){
            r = "none";
        }
        if(sign == 1){
            r = "lengths";
        }
        if(sign == 2){
            r = "lexicographically";
        }
        if(sign == 3){
            r = "both";
        }
        return r;
	}
};
