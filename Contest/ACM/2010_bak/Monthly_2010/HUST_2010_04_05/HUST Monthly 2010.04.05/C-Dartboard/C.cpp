#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int f[105],used[105];
int n;
int minus1;
int min1;
int t;
int ans;
int main()
{
freopen("Dartboard.in","r",stdin);
freopen("Dartboard.out","w",stdout);
cin >> t;
for (int cases = 0; cases < t; ++cases)
{
 	cin >> n;
    memset(f,0,sizeof(f));
    f[n+1] = 1000;
    f[0]   = 1000;
    ans = 0;
    memset(used,0,sizeof(used));
if (n % 4 != 0)
 {
  	f[1] = 2;
  	f[2] = n-1;
    used[n-1] = 1;
    used[2] = 1;
}
if(n % 4 == 0)
{
	f[1]      = n;
  	f[2]      =  1;
  	f[n-1]    = 2;
  	f[n]      = n-1;
    used[n]   = 1;
    used[n-1] = 1;
    used[2]   = 1;
    used[1]   = 1;
}

if (n%4!=0) 
{
  for (int i = 3; i <= n ; i++)
   {
   	if (i % 2 == 0) continue;
	for (int j = 1 ; j <= n ;j++)		  
	{
  		if (used[j] == 1) continue;
		if(((f[i-2]+j == n-1) && (f[i-1]+n+1-j == n+3)) ||  ((f[i-2]+j == n+3) &&( f[i-1]+n+1-j == n-1)))
		{
			used[j]  = 1;
			used[n+1-j] = 1; 
			f[i] = j; 
			f[i+1] = n+1-j; 
			break;
		}
		
 	}	    
   }		 
} 
   
if (n % 4 == 0) 
{
	for (int i = 3; i <= n ; i++)
    {
    	minus1 = 1000;
    	min1   =   -1;
    	if (i % 2 == 0) continue;
     		for (int k = 2;k <= n-1;k++ )
      		{
	   	 		if (f[k] == 0) continue;
		 		if ((abs(f[k]-n/2) > min1)&&((f[k-2] == 0) && (f[k-1] == 0) || (f[k+2] == 0)&& (f[k+1] == 0)))
		  		{
		   			min1   = f[k];
		   			minus1 = k;	
		  		}	  
 	  		}
 	    if (minus1 == 1000) continue; 
  		for (int j = 1 ; j <= n ;j++)
		{
		   	if (used[j] == 1) continue;	
		    if (f[minus1+2] == 0) 
			{
				if (abs(f[minus1]-j) == 2)
			 	{
 	          		used[j]     = 1; 
					used[n+1-j] = 1; 
					f[minus1+1] = j; 
					f[minus1+2] = n+1-j;  	
					break;					 
			 	} 	    
			}
			else 
			{
	  	  		if (abs(f[minus1]-j) == 2)
			 	{
 	          		used[j]     = 1; 
					used[n+1-j] = 1; 
					f[minus1-1] = j; 
					f[minus1-2] = n+1-j; 
					break;					 
			 	} 	 
			}
		}
   }		
} 
for (int i = 1; i <= n-2 ; i++)
{
	ans += (f[i]-f[i+2])*(f[i]-f[i+2]);
}
ans += (f[n-1]-f[1])*(f[n-1]-f[1]);
ans += (f[n]-f[2])*(f[n]-f[2]);
for (int i = 1; i <= n/2 ; i++)
{
	ans += (f[2*i-1]-f[2*i])*(f[2*i-1]-f[2*i]);
}
/*for (int i = 1; i <= n;i++)
{
   	cout << f[i] << " ";  	
} */
cout<<ans<<endl;
}
   return 0;
}
