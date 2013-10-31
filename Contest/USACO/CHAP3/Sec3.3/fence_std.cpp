/* Prob #5: Riding the Fences */
#include <stdio.h>
#include <string.h>

#define MAXI 500
#define MAXF 1200
char conn[MAXI][MAXI];
int deg[MAXI];
int nconn;

int touched[MAXI];

int path[MAXF];
int plen;

/* Sanity check routine */
void fill(int loc)
{
	int lv;

	touched[loc] = 1;
	for (lv = 0; lv < nconn; lv++)
		if (conn[loc][lv] && !touched[lv])
			fill(lv);
}

/* Sanity check routine */
int is_connected(int st)
{
	int lv;
	memset(touched, 0, sizeof(touched));
	fill(st);
	for (lv = 0; lv < nconn; lv++)
		if (deg[lv] && !touched[lv])
			return 0;
	return 1;
}

/* this is exactly the Eulerian Path algorithm */
void find_path(int loc)
{
	int lv;

	for (lv = 0; lv < nconn; lv++)
		if (conn[loc][lv])
		{
			/* delete edge */
			conn[loc][lv]--;
			conn[lv][loc]--;
			deg[lv]--;
			deg[loc]--;

			/* find path from new location */
			find_path(lv);
		}

	/* add this node to the `end' of the path */
	path[plen++] = loc;
}

int main(int argc, char **argv)
{
	FILE *fin, *fout;
	int nfen;
	int lv;
	int x, y;

	if (argc == 1) 
	{
		if ((fin = fopen("fence.in", "r")) == NULL)
		{
			perror ("fopen fin");
			//exit(1);
		}
		if ((fout = fopen("fence.out", "w")) == NULL)
		{
			perror ("fopen fout");
			//exit(1);
		}
	} else {
		if ((fin = fopen(argv[1], "r")) == NULL)
		{
			perror ("fopen fin filename");
			//exit(1);
		}
		fout = stdout;
	}

	fscanf (fin, "%d", &nfen);
	for (lv = 0; lv < nfen; lv++)
	{
		fscanf (fin, "%d %d", &x, &y);
		x--; y--;
		conn[x][y]++;
		conn[y][x]++;
		deg[x]++;
		deg[y]++;
		if (x >= nconn) nconn = x+1;
		if (y >= nconn) nconn = y+1;
	}

	/* find first node of odd degree */
	for (lv = 0; lv < nconn; lv++)
		if (deg[lv] % 2 == 1) break;
	/* if no odd-degree node, find first node with non-zero degree */
	if (lv >= nconn)
		for (lv = 0; lv < nconn; lv++)
			if (deg[lv]) break;
#ifdef CHECKSANE
	if (!is_connected(lv)) /* input sanity check */
	{
		fprintf (stderr, "Not connected?!?\n");
		return 0;
	}
#endif

	/* find the eulerian path */
	find_path(lv); 

	/* the path is discovered in reverse order */
	for (lv = plen-1; lv >= 0; lv--)
		fprintf (fout, "%i\n", path[lv]+1);
	return 0;
}
