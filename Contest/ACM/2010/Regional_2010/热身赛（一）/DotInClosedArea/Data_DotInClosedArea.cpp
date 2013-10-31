#include <iostream>
#include <fstream>
using namespace std;

int n;
int vertex[200][2];
int tx,ty;

inline int min(int a, int b){
    return a > b ? b : a;
}

inline int max(int a, int b){
    return a > b ? a : b; 
}       
inline int det(int x1, int y1, int x2, int y2){
    return x1*y2 - x2*y1;
} 
int onSegment(int x1, int y1, int x2, int y2, int x3, int y3){
    if(min(x1, x2) <= x3 && x3 <= max(x1, x2) && 
       min(y1, y2) <= y3 && y3 <= max(y1, y2) &&
       det(x3-x1, y3-y1, x3-x2, y3-y2) == 0)
    {
         return 1;
    }    
    return 0;
}    
int mul(int x, int y){
    if(x >=0 && y <= 0)return -1;
    if(x <=0 && y >= 0)return -1;   
    return 1;
}    
int isInFencing(){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(onSegment(vertex[i][0], vertex[i][1], vertex[i+1][0], vertex[i+1][1], tx, ty)){
            //cout<<"onsegment"<<endl;
            return 1;
        }    
        if(vertex[i][1] != vertex[i+1][1]){
            if((vertex[i][0] >= tx && vertex[i][1] == ty) || 
               (vertex[i+1][0] >=tx && vertex[i+1][1] == ty)){
                   
                if(vertex[i][1] > vertex[i+1][1]){
                    if(vertex[i][1] == ty)count++;
                }
                else{        
                    if(vertex[i+1][1] == ty)count++;
                }
                //cout<<"xxxxxxxxxxxxxxxxxxxxxxxx   "<<count<<endl;
            }   
            else{
                
                long long t1=det(tx-vertex[i][0], ty-vertex[i][1], vertex[i+1][0]-vertex[i][0], vertex[i+1][1]-vertex[i][1]);
                long long t2=det(1000000-vertex[i][0], ty-vertex[i][1], vertex[i+1][0]-vertex[i][0], vertex[i+1][1]-vertex[i][1]);
                long long t3=det(vertex[i][0]-tx, vertex[i][1]-ty, 1000000-tx, 0);
                long long t4=det(vertex[i+1][0]-tx, vertex[i+1][1]-ty, 1000000-tx, 0);
                //cout<<t1<<"   "<<t2<<"    "<<t3<<"    "<<t4<<endl;
                if(mul(t1, t2)<=0 && mul(t3,t4)<=0)count++;
                //cout<<"yyyyyyyyyyyyyyyyyyyyyyyy   "<<count<<endl;
            }    
        }
        //else cout<<"aaaaaaaaaaaaaaaaaaaaa    "<<count<<endl;
    }
    //cout<<"count "<<count<<endl;
    if(count % 2==1)return 1;
    else return 0;
}            

                
    
int main(){
    ifstream fin("DotInClosedArea.in");
    ofstream fout("DotInClosedArea.out");
    int t;
    fin >> t;
    
    while(t--){
        fin >> n;
        
        fin >> tx >> ty;
        
        for(int i = 0; i < n; i++)
            fin >> vertex[i][0] >> vertex[i][1];
            
        vertex[n][0] = vertex[0][0];
        vertex[n][1] = vertex[0][1];
        
        if(isInFencing()){
            printf("yes\n");
            fout<<"yes"<<endl;
            continue;
        }    
        printf("no\n");
        fout<<"no"<<endl;
    }
    system("pause");
    return 0;
}        
        
        
