#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>

using namespace std;

void work4(int n){
     int m=n*1000;
     cout << n << " " << m << endl;
     for (int i=0;i<n;i++)
         cout << rand()%1000 << " ";
     cout << endl;
     }
     
int a[200010]; 
     
void work1(int n){
     int m=0;
     for (int i=0;i<n;i++){
         a[i]=rand()%1000;
         m+=a[i];
     }
     m=m/(rand()%100+20);
     cout << n << " " << m << endl;
     for (int i=0;i<n;i++)
     cout << a[i] << " ";
     cout << endl;
     }
     
void work2(int n){
     cout << n << " " << n*3-1 << endl;
     for (int i=0;i<n;i++)
         cout << 3 << " ";
     cout << endl;
     }
     
void work3(int n){
     cout << n << " " << n/2-1 << endl;
     for (int i=0;i<n;i++)
         cout << i%2 << " ";
     cout << endl;
     }

int main(){
    freopen("interview.in","w",stdout);
    work4(100);
    work2(200000);
    work3(200000);
    work1(10);
    work1(100);
    work1(100000);
    return 0;
}