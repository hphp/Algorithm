/*
2014-05-27
8:36-8:48
easy bag problem
get 443.08 points.
and for the first time
and let it go!!!
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;
#define N 2001

bool able_get[N][N];

class PairGameEasy{
    public:
        string able(int a, int b, int c, int d){
            for(int i = 0; i <= c ; i ++) 
                for(int j =0 ; j <= d; j ++)
                    able_get[i][j] = 0;

            able_get[a][b] = 1;
            for(int i = a; i <= c; i ++)
                for(int j=b; j<= d; j ++){
                    if(able_get[i][j]){
                        able_get[i+j][j] = 1;
                        able_get[i][i+j] = 1;
                    }
                }
            if(able_get[c][d]){
                return "Able to generate";
            }
            else return "Not able to generate";
        }
};
