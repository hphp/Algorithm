#include <stdio.h>

int con[10] = 
{
1,0,0,0,1,0,1,0,2,1
};//0 1 2 3 4 5 6 7 8 9 

class DigitHoles
{
	public :
	int numHoles(int number)
	{
		int sum = 0;
		int tmp = number;
		while(tmp)
		{
			sum += con[tmp%10];
			tmp/=10;	
		}
		return sum;
	}	
};
