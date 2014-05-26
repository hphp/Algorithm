/*
2014-05-26
a whole afternoon , from 14:20 - 17:20 - 
waste a lot of time,
first of all, can not sense the main method.
second, after completion of codes, gets wrong answer.
and , think for a little while , then nail it.
get a point of 86.37
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;

struct PointInfo{
    double x;
    int label;
    int rank;
}point_info[500];

bool cmp(PointInfo a, PointInfo b){
    return a.x < b.x;
}

class RadioRange{
    double distance(int x, int y){
        double xx = double(x);
        double yy = double(y);
        return sqrt(xx*xx + yy*yy);
    }
    public:
        double RadiusProbability(vector <int> X, vector<int> Y, vector<int> R, int Z){
            double min_dis = Z;
            double max_dis = 0;
            int n = 0;
            for(int i = 0 ; i < X.size(); i ++){
                double dis = distance(X[i],Y[i]);
                double n_dis = max(0,dis-R[i]);
                double x_dis = min(Z,dis+R[i]);
                point_info[n].x = n_dis;
                point_info[n].label = n;
                n++;
                point_info[n].x = x_dis;
                point_info[n].label = n;
                n++;
                printf("%lf,%lf,%lf\n",dis,n_dis,x_dis);
            }
            point_info[n].x = Z;
            point_info[n].label = n;
            n++;
            sort(point_info,point_info+n,cmp);
            int position[300] = {0};
            for(int i = 0 ;i < n ; i ++){
                position[point_info[i].label] = i;
                point_info[i].rank = i;
            }
            int dye[500] = {0};
            for(int i = 0 ;i < X.size(); i ++){
                PointInfo seg_info[2] = {point_info[position[i*2]], point_info[position[i*2+1]]};
                for(int j = seg_info[0].rank+1; j <= seg_info[1].rank; j ++){
                    dye[j] = 1; 
                }
            }
            double total_avl = max(0,point_info[0].x);
            for(int j = 1 ; j < n ; j ++){
                if(point_info[j].x < 0)
                    continue;
                if(dye[j] == 0){
                    total_avl += max(0,point_info[j].x - point_info[j-1].x) ;
                } 
            }
            double probability = 1;
            if(Z!=0)
                probability = total_avl / Z;
            return probability;
        }
};
/*
int main(){
    RadioRange rr = RadioRange();
    vector<int> X,Y,R;
    int XX[100] = {0, -60, 62, -60, 63, -97};//0};
    int YY[100] = {-72, 67, 61, -8, -32, 89};
    int RR[100] = {6, 7, 8, 7, 5, 6};
    int Z = 918;
    int n = 6;
    for(int i = 0 ; i < n; i ++){
        X.push_back(XX[i]); 
        Y.push_back(YY[i]); 
        R.push_back(RR[i]); 
    }
    double p = rr.RadiusProbability(X,Y,R,Z);
    printf("%lf\n",p);
    return 0;
}
*/
    /*
    int XX[5] = {20, -20, 0, 0};
    int YY[5] = {0, 0, 20, -20};
    int RR[6] = {50, 50, 50, 50};
    int Z = 100;
    int n = 4;
    */
    /*
    int XX[100] = {1000000000};
    int YY[100] = {1000000000};
    int RR[100] = {1000000000};
    int Z = 1000000000;
    int n = 1;
    */
