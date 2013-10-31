#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

int		A	[120][120];
int		B	[120][120];

void	gen_matrix(int mat[120][120] , int n , int m)
{
	int	i , j;
	for (i = 0; i < n; i ++)
		for (j = 0; j < m; j ++)
			mat[i][j] = rand() % 2;
}

void	print(int mat[120][120] , int n , int m)
{
	int	i , j;
	for (i = 0; i < n; i ++)
	{
		for (j = 0; j < m; j ++)
		{
			if (j) putchar(' ');
			printf("%d" , mat[i][j]);
		}
		putchar('\n');
	}
}

void	gen_ran(int n , int m)
{
	printf("%d %d\n" , n , m);
	gen_matrix(A , n , m);
	gen_matrix(B , n , m);
	print(A , n , m);
	print(B , n , m);
}

void	gen_yes(int n , int m)
{
	printf("%d %d\n" , n , m);

	gen_matrix(A , n , m);
	memcpy(B , A , sizeof(B));

	int	i , j , p , k , t;

	for (i = 0; i < n; i ++)
	{
		for (t = 0; t < 3; t ++)
		{
			if (rand() % 2)
			{
				for (j = 0; j < m; j ++)
					B[i][j] = 1 - B[i][j];
			}
		}
	}

	for (p = 0; p < m; p ++)
	{
		i = rand() % m;
		j = rand() % m;

		for (k = 0; k < n; k ++)
		{
			t = B[k][i];
			B[k][i] = B[k][j];
			B[k][j] = t;
		}
	}

	print(A , n , m);
	print(B , n , m);
}

void	gen_yes_noise(int n , int m)
{
	printf("%d %d\n" , n , m);

	gen_matrix(A , n , m);
	memcpy(B , A , sizeof(B));

	int	i , j , p , k , t;

	for (i = 0; i < n; i ++)
	{
		for (t = 0; t < 3; t ++)
		{
			if (rand() % 2)
			{
				for (j = 0; j < m; j ++)
					B[i][j] = 1 - B[i][j];
			}
		}
	}

	for (p = 0; p < m; p ++)
	{
		i = rand() % m;
		j = rand() % m;

		for (k = 0; k < n; k ++)
		{
			t = B[k][i];
			B[k][i] = B[k][j];
			B[k][j] = t;
		}
	}

	int	x , y;

	for (i = 0; i < 3; i ++)
	{
		x = rand() % n;
		y = rand() % m;
		B[x][y] = 1 - B[x][y];
	}

	print(A , n , m);
	print(B , n , m);
}


int	main()
{
	freopen("matrix.in" , "w" , stdout);

	srand( time(0) );

	gen_yes(5 , 5);
	gen_ran(10 , 10);
	gen_yes(10 , 10);
	gen_ran(10 , 10);
	gen_ran(20 , 30);
	gen_ran(50 , 60);
	gen_yes_noise(50 , 60);
	gen_yes(80 , 80);
	gen_yes(100 , 100);
	gen_ran(100 , 100);
	gen_ran(100 , 100);
	gen_yes_noise(100 , 100);
	gen_yes(100 , 100);
	gen_yes_noise(100 , 100);

	puts("-1 -1");

	return 0;
}
