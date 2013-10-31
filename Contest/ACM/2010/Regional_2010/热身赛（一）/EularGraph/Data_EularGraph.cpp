#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int map[100][100];
int used[100][100];
int visited[100];
int n;
int vertex[100][2];

int random(int low, int high){
    return low + rand() % (high-low+1);
}  
  
void trace(int k){
    int i;
    for(i=1; i<=n; i++){
        if(i!=k && map[k][i]==1 && visited[i]==0){
            visited[i] = 1;
            trace(i);
        }
    }
}
            
int main(){
    srand(time(NULL));
    ofstream fout1("ConnectiveGraph.in");
    ofstream fout2("ConnectiveGraph.out");
    int t,m,a,b,i,j;
    t = random(50,99);
    fout1 << t << endl;
    while(t--){
        
        memset(map, 0, sizeof(map));
        memset(used, 0, sizeof(used));
        memset(visited, 0, sizeof(visited));
        memset(vertex, 0, sizeof(vertex));
        
        n = random(10, 20);
        m = random(n, n*n);
        
        fout1 << n << " " << m << endl;
        
        for(i=0; i<m; i++){
            a = random(1, n);
            b = random(1, n);
            while(b==a){
                b = random(1, n);
            }
            map[a][b] = 1;
            vertex[a][0]++;
            vertex[b][1]++;
            fout1 << a << " " << b << endl;
        }
        
        visited[1] = 1;
        trace(1);
        
        for(i=1; i<=n; i++){
            if(visited[i] == 0)break;
        }
        if(i>n){
            for(j=1; j<=n; j++){
                if(vertex[j][0]!=vertex[j][1])break;
            }    
            if(j>n){
                fout2 << "yes" << endl;
                cout << "yes" << endl;
                continue;
            }    
        }  
          
        fout2 << "no" << endl;
        cout << "no" << endl;
  
        cout << endl << endl;
    }
    system("pause");
    return 0;
}        
            
                
    
    
