//2010-05-10-09:53---11:00
//14:00--15:35
//2010-05-11-14:30----15:48 ---AC

/*
total time : 240 min
�������ڣ����ʱ�䲢���ǺܶࣻҲ�������� ��
ʵ�ֵ�ʱ���sb��
1.���ڸ������������������������ʮ��һ�������ǿ�ʼ��û�п��ǵ��� 
2.��������������ʱ��û�����ʮ�ֺ������ȷ����ȷ�� 
3.�ֲ���������ȫ�ֱ�����ʡ�ĺ�����ֵ��--wa������ 
SHINING POINTS: 
0.��ȫ�Լ�������ġ� 
1.��ĺ������
2.д�Ķ�������û��̫��ı䣬Ҳ֤��������������ǰҪǿ���ܶ�
3.������ĺܲ�����Ϊ���������˺ܶ����⡣
4.����Ƚ������ģ�������wa���ڼ䣬��û�����ð�ʱ����˼�����⡣

����״̬��
mn[id][flag]��ʾ��������flag������������ʱ����ȫ����������Ҫ�ӵ����ٵı�����
�������ڸ��ڵ�������ԣ�ֻ��Ҫ�����������������һЩ�����Ϳ����ˡ� 

flag = 0 :
	�ڱ��������֮�����ջص���ǰ���ڵ㡣
flag = 1:
	�Ӹ��ڵ��������һ��������ĳһ�ڵ�ֹͣ��
flag = 2:
	��һ��������ĳһ�ڵ����������ĳһ������ĳһ�ڵ�ֹͣ��
	
���ݶ����ļ��������ö�٣�
����[0,1,2]���������Ҫ��SUM(CiMin[0,1,2]) i ���ڵ�ǰ���ڵ�Ķ��ӵı�� .�����ڲ�ͬ��flag �� ��Ҫ����һ����������
Cx[flag'] - CxMin[0,1,2] 
���flag' ����flag�仯���仯
��Ӧ��ϵ��
flag  flag ' 
0      0
1      1
2      0 1 ��֤�ֱ��Ӧ��ͬ��Cx  


*/
#include <stdio.h>
#define N 100100
#define MAX (1<<30)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

struct Node
{
	int id;
	Node * next;	
}node[N],edge[N*2];
int tt;
int n;
int flag[N];

void node_init()
{
	tt = 0;
	for(int i=1;i<=n;i++)	
	{
		flag[i] = -1;
		node[i].next = NULL;	
	}
}

void add_edge(int a,int b)
{
	edge[tt].id = b;
	edge[tt].next = node[a].next;
	node[a].next = & edge[tt];
	tt ++;
}

int mn[N][4];

void deal(int id,int & cnt,int flag,int add[],int extra[4][2],int recid[4][2])
{
	int tmp = mn[id][0] - mn[id][3];
	if(tmp < add[0])
	{
		add[0] = tmp;
	}
	tmp = mn[id][1] - mn[id][3];
	if(tmp < add[1])
	{
		add[1] = tmp;
	}
	if(cnt < 2)
	{
		extra[cnt][0] = mn[id][0]-mn[id][3];
		recid[cnt][0] = id;
		extra[cnt][1] = mn[id][1]-mn[id][3];
		recid[cnt][1] = id;
	/*
		if(flag == -1)
		{
			printf("extra:%d %d\n",extra[cnt][0],recid[cnt][0]);
			printf("extra:%d %d\n",extra[cnt][1],recid[cnt][1]);
		}
	*/
		cnt ++;
	}
	else if(cnt == 2)
	{
		for(int kk = 0;kk<2;kk++)
		{
			tmp = mn[id][kk] - mn[id][3];
			for(int jj=1;jj>=0;jj--)
			{
				if(extra[jj][kk] > tmp)
				{
					extra[jj+1][kk] = extra[jj][kk];
					recid[jj+1][kk] = recid[jj][kk];
					extra[jj][kk] = tmp;
					recid[jj][kk] = id;
				}
			}
		}
	}
}

int getAdd(int flag,int extra[4][2],int recid[4][2])
{
/*	if(recid[0][0] != recid[0][1])
	{
		return extra[0][0]+extra[0][1];
	}
	else*/
		
	{
		int a = MAX;
		int mnmn = MAX;
		int cnt = 0;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
			{
				if(recid[i][0] != recid[j][1])
				{
					a = extra[i][0] + extra[j][1];
		/*
					if(flag == -1)
					{
						printf("%d %d %d %d %d\n",recid[i][0],extra[i][0],recid[j][1],extra[j][1],a);
					}
		*/
					if(a < mnmn)
						mnmn = a;
				}
			}
		return mnmn;
	}
}

int subtract[4] = {1,1,2};

void dp(int cur)
{
	flag[cur] = 1;
	int stcnt = 0;
	int extra[4][2],recid[4][2];
	int add[4];
	for(int i=0;i<4;i++)
	{
		add[i] = MAX;
		mn[cur][i] = MAX;
		for(int j=0;j<2;j++)
		{
			extra[i][j] = MAX;
			recid[i][j] = MAX;
		}
	}
	int cnt = 0;
	int sum = 0;
	for(Node * tmp = node[cur].next ; tmp != NULL ; tmp = tmp->next)
	{
		int id = tmp->id;
		if(flag[id] == -1)
		{
			stcnt ++;
			dp(id);
			sum += mn[id][3];
	/*
			if(cur == 1)
				printf("%d %d\n",id,cnt);
	*/
			int ss = 0;
			if(cur == 1)ss = -1;
			deal(id,cnt,ss,add,extra,recid);
		//	printf("cnt:%d\n",cnt);
		}
	}
	if(stcnt > 1)
	{
		int ref = 0;
		if(cur == 1)
			ref = -1;
		add[2] = getAdd(ref,extra,recid);
	}
	if(stcnt == 0)
	{
		mn[cur][0] = 0;
		mn[cur][1] = 0;
		mn[cur][3] = 0;
		return;
	}
	int lim = Min(3,stcnt+1);
	for(int i=0;i<lim;i++)
	{
		mn[cur][i] = sum + add[i] + stcnt - subtract[i];
	/*	
		if(cur == 1)
			printf("cur : %d kind %d sum %d add %d addedge%d\n",cur,i,sum,add[i],stcnt-subtract[i]);
	*/	
		if(mn[cur][i] < mn[cur][3])
			mn[cur][3] = mn[cur][i];
	}
}

int main()
{
	int a,b;
	while(scanf("%d",&n)!=EOF)
	{
		node_init();
		for(int i=1;i<n;i++)
		{
			scanf("%d %d",&a,&b);
			add_edge(a,b);	
			add_edge(b,a);
		}
		dp(1);
	/*	while(scanf("%d %d",&a,&b)!=EOF)
		{
			if(!(a||b))break;
			printf("%d %d\n",mn[a][b],mn[a][3]);
		}*/
		int ans = Min(mn[1][2]+1,mn[1][1]+1);
//		printf("%d %d\n",mn[1][2],mn[1][1]);
		printf("%d\n",ans);
	}
	return 0;
}
