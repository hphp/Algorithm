#include <cstdio>
#define SIZE (1<<m)
#define MAX_SIZE 32
using namespace std;

class CMatrix
{
    public:
        long element[MAX_SIZE][MAX_SIZE];
        void setSize(int);
        void setModulo(int);
        CMatrix operator* (CMatrix);
        CMatrix power(int);
    private:
        int size;
        long modulo;
};

void CMatrix::setSize(int a)
{
    for (int i=0; i<a; i++)
        for (int j=0; j<a; j++)
            element[i][j]=0;
    size = a;
}

void CMatrix::setModulo(int a)
{
    modulo = a;
}

CMatrix CMatrix::operator* (CMatrix param)
{
    CMatrix product;
    product.setSize(size);
    product.setModulo(modulo);
    for (int i=0; i<size; i++)
        for (int j=0; j<size; j++)
            for (int k=0; k<size; k++)
            {
                product.element[i][j]+=element[i][k]*param.element[k][j];
                product.element[i][j]%=modulo;
            }

    return product;
}

CMatrix CMatrix::power(int exp)
{
    CMatrix tmp = (*this) * (*this);
    if (exp==1) return *this;
    else if (exp & 1) return tmp.power(exp/2) * (*this);
    else return tmp.power(exp/2);
}


int pow10[12];
void init()
{
	int a = 1;
	pow10[0] = 1;
	for(int i=1;i<10;i++)
		pow10[i] = pow10[i-1]*10;
}

int main()
{
    const int validSet[]={0,3,6,12,15,24,27,30};
    long n, m, p;
    CMatrix unit;
    
    int test;
    scanf("%d",&test);
    init();
    for(int tt = 1; tt <= test; tt ++)
    {
		scanf("%d%d",&n,&p);
		if(n > 1)
			n --;
			
	    unit.setSize(2);
	    
	    unit.element[0][0] = 0;
	    unit.element[0][1] = 1;
	    unit.element[1][0] = 1;
	    unit.element[1][1] = 1;
	
		unit.setModulo(p);
		
		int a = unit.power(n).element[1][1];
		
	    printf("%d\n",a);
	}
    return 0;
}
