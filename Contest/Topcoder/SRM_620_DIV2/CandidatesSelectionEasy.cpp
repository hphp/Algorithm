/*
2014-05-27
from 8:xx - 8:36
get a point of 199.52, did not get the problem at first time.
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

struct CeilInfo{
    int score;
    int label;
}ceil_list[100];

bool cmp(CeilInfo a, CeilInfo b){
    if(a.score > b.score)
        return 1;
    if(a.score < b.score)
        return 0;
    if(a.score == b.score)
        return a.label < b.label;
}

class CandidatesSelectionEasy{
    public:
        vector <int> sort(vector <string> score, int x){
            for(int i =0  ; i < score.size(); i ++){
                int sc = 26-(score[i][x]-'A');
                ceil_list[i].score = sc;
                ceil_list[i].label = i;
            }
            std::sort(ceil_list, ceil_list+score.size(), cmp);
            vector<int> sorting_result;
            for(int i =0 ; i < score.size(); i ++){
                sorting_result.push_back(ceil_list[i].label);
            }
            return sorting_result;
        }
};
