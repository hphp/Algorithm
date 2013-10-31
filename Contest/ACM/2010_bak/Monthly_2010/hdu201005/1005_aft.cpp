#include <stdio.h>
#define T 2002
#define MAXP 2002
#define MAX (1<<28)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

int mx[T][MAXP],mxb[T][MAXP];
int as[T],bs[T],ap[T],bp[T];
int day,maxP,w;
int recMx[MAXP];
/// 单调队列 
struct Node
{
	int id;
	int v;
	Node * next;
	Node * last;
}node[T];

bool cmpv0(Node * a , Node * b)
{
	if(a->v<b->v)
		return true;
	return false;
}

class MonnotonePriorityQueue
{
	public:
		void clear()
		{
			head = NULL;
			tail = NULL;	
		}
		MonnotonePriorityQueue()
		{
			head = NULL;	
			tail = NULL;	
		}
		Node * head;
		Node * tail;
		void insert(Node *,bool (*cmp)(Node * a , Node * b));
		int query(int);
}mpq;

void MonnotonePriorityQueue::insert(Node * cur , bool (*cmp)(Node * a,Node * b))
{
	if( head == NULL )
	{
		head = cur;
		tail = cur;
	}
	else
	{
		Node * tmp = tail;
		bool flag = cmp(tmp,cur);
		while( tmp != NULL && flag)
		{
			tmp = tmp->last;
			if(tmp != NULL)
			flag = cmp(tmp,cur);
		}
		if(tmp == NULL)
		{
			head = cur;
			tail = cur;
			cur->next = NULL;
			cur->last = NULL;
		}
		else
		{
			tmp->next = cur;
			cur->last = tmp;
			cur->next = NULL;
			tail = cur;
		}

	}
}

int MonnotonePriorityQueue::query(int st)
{
	Node * cur = head;
	while(cur != NULL && cur->id <st)
	{
		cur = cur->next;	
	}
	head = cur;
	cur->last = NULL;
	return cur->v;
}

void dp_init()
{
	for(int i=0;i<=day;i++)
		for(int j=0;j<=maxP;j++)
		{
			mx[i][j] = -MAX;
			mxb[i][j] = -MAX;
		}
	mx[0][0] = 0;
	mxb[0][0] = 0;
}
int getVB(int i0,int j,int i)
{
	if(mxb[i0][j] == -MAX)
		return -MAX;
	return mxb[i0][j] + j * ap[i];
}

void getRecMx(int i,int i0)
{
	for(int ii=0;ii<=maxP;ii++)
		recMx[ii] = -MAX;
	mpq.clear();
	for(int j=0;j<=maxP;j++)
	{
		node[j].id = j;
		node[j].v = getVB(i0,j,i);
//		printf("%dhei",node[j].v);
		node[j].next = node[j].last = NULL;
		mpq.insert(&node[j],cmpv0);
		int lm = Max(j-as[i],0);
		recMx[j] = mpq.query(lm);
//			printf("%d ",recMx[j]);
	}
//	printf("i:%d \n",i);
}

int getVS(int i0,int j,int i)
{
	if(mxb[i0][j] == -MAX)
		return -MAX;
	return mxb[i0][j] + j * bp[i];
}

void getRecMx0(int i,int i0)
{
	for(int it=0;it<=maxP;it++)
		recMx[it] = -MAX;
	mpq.clear();
	for(int j=0;j<=maxP;j++)
	{
		node[j].id = j;
		node[j].v = getVS(i0,j,i);
		node[j].next = node[j].last = NULL;
		mpq.insert(&node[j],cmpv0);
		int lm = Max(j-bs[i],0);
		recMx[lm] = mpq.query(lm);
//		printf("%d ",recMx[j]);
	}
	//	printf("left lm %d\n",maxP-bs[i]+1);
	for(int j=Max(maxP-bs[i]+1,0);j<=maxP;j++)
	{
		int lm = j;
		recMx[lm] = mpq.query(lm);
//		printf("%d ",recMx[j]);
	}
//	printf("/// i:%d \n",i);
}


int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		scanf("%d %d %d",&day,&maxP,&w);
		for(int i=1;i<=day;i++)
		{
			scanf("%d %d %d %d",&ap[i],&bp[i],&as[i],&bs[i]);
			if(as[i] > maxP)
				as[i] = maxP;
			if(bs[i] > maxP)
				bs[i] = maxP;
		}
		dp_init();
		mpq.clear();
		for(int i=1;i<=day;i++)
		{
			int i0 = Max(i-w-1,0);

			getRecMx(i,i0);
			
			for(int j=0;j<=maxP;j++)
			{
				int maxx = recMx[j];
				if(maxx != -MAX)
					mx[i][j] = Max(maxx - ap[i]*j,mx[i][j]);
			}
			
			getRecMx0(i,i0);
			
			for(int j=0;j<=maxP;j++)
			{
				int rm = j;
			//	if(i==2&&j==maxP)
				//	printf("hello rm %d\n",rm);
				//int rm = Min(j+bs[i],maxP);
				int maxx = recMx[rm];
				if(maxx > -MAX)
					mx[i][j] = Max(maxx - bp[i]*j,mx[i][j]);
			}

			for(int j=0;j<=maxP;j++)
			{
				mxb[i][j] = Max(mx[i][j],mxb[i-1][j]);
			}
        }
		int a,b;
/*		while(scanf("%d %d",&a,&b)!=EOF)
		{
			if(!(a||b))break;
			printf("%d\n",mx[a][b]);
		}*/
		int mxmx = 0;
		for(int j=0;j<=maxP;j++)
			if(mxb[day][j] > mxmx)
				mxmx = mxb[day][j];
		printf("%d\n",mxmx);
	}
	return 0;
}
