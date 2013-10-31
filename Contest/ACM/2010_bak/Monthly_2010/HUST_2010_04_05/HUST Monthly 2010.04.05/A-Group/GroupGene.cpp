#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void gene(int n, int k, int l){
	cout<<n<<" "<<k<<" "<<l<<endl;
	for (int i=0; i<n-1; i++) cout<<rand()%2000-1000<<" ";
	cout<<rand()%2000-1000<<endl;	
}

void gene2(int n, int k, int l, int sign){
	cout<<n<<" "<<k<<" "<<l<<endl;
	for (int i=0; i<n-1; i++) cout<<1000*sign<<" ";
	cout<<1000*sign<<endl;
}

void gene3(int n, int k, int l, int x, int sign){
	cout<<n<<" "<<k<<" "<<l<<endl;
	for (int i=0; i<n-1; i++) cout<<(rand()%x+1)*sign<<" ";
	cout<<(-1000)*sign<<endl;	
}

void gene4(int n, int k, int l, int x, int sign){
	cout<<n<<" "<<k<<" "<<l<<endl;
	cout<<(-1000)*sign<<" ";
	for (int i=0; i<n-1; i++) cout<<" "<<(rand()%x+1)*sign;
	cout<<endl;
}

int main(){
	freopen("Group.in","w",stdout);
	cout<<"20"<<endl;

	gene(10,1,1);
	gene(10,10,2);
	gene(100,100,1);
	gene(1000,100,5);

	for (int i=0; i<4; i++)
		gene(20000, 100, (rand()*i)%200+1);

	gene2(1,1,1,-1);
	gene2(20000,100,1,1);
	gene2(20000,100,1,-1);
	gene2(20000,100,200,1);
	gene2(20000,100,200,-1);

	gene3(200, 88, 10, 10, 1);
	gene3(1000, 100, 5, 10, -1);
	gene3(500, 88, 25, 1, 1);
	gene3(20000, 100, 100, 3, 1);
	
	gene4(100, 88, 15, 10, 1);
	gene4(100, 88, 20, 2, -1);
	gene4(20000, 100, 100, 3, -1);
}
