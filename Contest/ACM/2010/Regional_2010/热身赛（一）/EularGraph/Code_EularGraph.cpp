#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int map[100][100];
int used[100][100];
int visited[100];
int n;
int vertex[100][2];

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
    
    //freopen("ConnectiveGraph.in", "r", stdin);
    //freopen("abc.out", "w", stdout);

    int t,m,a,b,i,j;
    
    scanf("%d", &t);
    
    while(t--){
        
        memset(map, 0, sizeof(map));
        memset(used, 0, sizeof(used));
        memset(visited, 0, sizeof(visited));
        
        scanf("%d%d", &n, &m);
        
        for(i=0; i<m; i++){
            scanf("%d%d", &a, &b);
            map[a][b] = 1;
            vertex[a][0]++;
            vertex[b][1]++;
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
                cout << "yes" << endl;
                continue;
            }    
        }    
        cout << "no" << endl;
    }
    system("pause");
    return 0;
}        
            
                
    
    
