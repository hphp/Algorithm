
struct B
{
	int w;
	int add[4];
	int dis[4];
}

struct A
{
	int cnt;
	struct B b[4];
};

struct A p[7];


void init()
{
	//0
	p[0].cnt = 2;
	//00
	p[0].b[0].w = 4;
	p[0].b[0].add[0] = 1;
	p[0].b[0].add[1] = 1;
	p[0].b[0].add[2] = 1;
	p[0].b[0].add[3] = 1;
	p[0].b[0].dis[0] = 0;
	p[0].b[0].dis[1] = 0;
	p[0].b[0].dis[2] = 0;
	p[0].b[0].dis[3] = 0;
	//01
	p[0].b[1].w = 1;
	p[0].b[1].add[0] = 4;
	p[0].b[1].dis[0] = 0;


	//1
	p[1].cnt = 4;
	//10
	p[1].b[0].w = 3;
	p[1].b[0].add[0] = 2;
	p[1].b[0].add[1] = 1;
	p[1].b[0].add[2] = 1;
	p[1].b[0].dis[0] = 0;
	p[1].b[0].dis[1] = 0;
	p[1].b[0].dis[2] = 0;
	//11
	p[1].b[1].w = 2;
	p[1].b[1].add[0] = 3;
	p[1].b[1].add[1] = 1;
	p[1].b[1].dis[0] = 0;
	p[1].b[1].dis[1] = 2;
	//12
	p[1].b[2].w = 3;
	p[1].b[2].add[0] = 1;
	p[1].b[2].add[1] = 1;
	p[1].b[2].add[1] = 2;
	p[1].b[2].dis[0] = 0;
	p[1].b[2].dis[1] = 0;
	p[1].b[2].dis[2] = -1;
	//13
	p[1].b[3].w = 2;
	p[1].b[3].add[0] = 1;
	p[1].b[3].add[1] = 3;
	p[1].b[3].dis[0] = 0;
	p[1].b[3].dis[1] = 0;
	
	
	//2
	p[1].cnt = 4;
	//20
	p[2].b[0].w = 3;
	p[2].b[0].add[0] = 1;
	p[2].b[0].add[1] = 1;
	p[2].b[0].add[2] = 2;
	p[2].b[0].dis[0] = 0;
	p[2].b[0].dis[1] = 0;
	p[2].b[0].dis[2] = 0;
	//21
	p[2].b[1].w = 2;
	p[2].b[1].add[0] = 3;
	p[2].b[1].add[1] = 1;
	p[2].b[1].dis[0] = 0;
	p[2].b[1].dis[1] = 0;
	//22
	p[2].b[2].w = 3;
	p[2].b[2].add[0] = 2;
	p[2].b[2].add[1] = 1;
	p[2].b[2].add[1] = 1;
	p[2].b[2].dis[0] = 0;
	p[2].b[2].dis[1] = 1;
	p[2].b[2].dis[2] = 1;
	//23
	p[2].b[3].w = 2;
	p[2].b[3].add[0] = 1;
	p[2].b[3].add[1] = 3;
	p[2].b[3].dis[0] = 0;
	p[2].b[3].dis[1] = -2;
	
	//3
	p[3].cnt = 1;
	//30
	p[3].b[0].w = 2;
	p[3].b[0].add[0] = 2;
	p[3].b[0].add[1] = 2;
	p[3].b[0].dis[0] = 0;
	p[3].b[0].dis[1] = 0;
	
	
	//4
	p[4].cnt = 2;
	//40
	p[4].b[0].w = 3;
	p[4].b[0].add[0] = 1;
	p[4].b[0].add[1] = 2;
	p[4].b[0].add[2] = 1;
	p[4].b[0].dis[0] = 0;
	p[4].b[0].dis[1] = 0;
	p[4].b[0].dis[2] = 1;
	//41
	p[4].b[1].w = 2;
	p[4].b[1].add[0] = 2;
	p[4].b[1].add[1] = 2;
	p[4].b[1].dis[0] = 0;
	p[4].b[1].dis[1] = -1;
	
	
	//5
	p[5].cnt = 4;
	//50
	p[5].b[0].w = 3;
	p[5].b[0].add[0] = 1;
	p[5].b[0].add[1] = 2;
	p[5].b[0].add[2] = 1;
	p[5].b[0].dis[0] = 0;
	p[5].b[0].dis[1] = 0;
	p[5].b[0].dis[2] = 0;
	//51
	p[5].b[1].w = 2;
	p[5].b[1].add[0] = 3;
	p[5].b[1].add[1] = 1;
	p[5].b[1].dis[0] = 0;
	p[5].b[1].dis[1] = 1;
	//52
	p[5].b[2].w = 3;
	p[5].b[2].add[0] = 1;
	p[5].b[2].add[1] = 2;
	p[5].b[2].add[2] = 1;
	p[5].b[2].dis[0] = 0;
	p[5].b[2].dis[1] = -1;
	p[5].b[2].dis[2] = 0;
	//53
	p[5].b[3].w = 2;
	p[5].b[3].add[0] = 1;
	p[5].b[3].add[1] = 3;
	p[5].b[3].dis[0] = 0;
	p[5].b[3].dis[1] = -1;
	
	
	//6
	p[6].cnt = 2;
	//60
	p[6].b[0].w = 3;
	p[6].b[0].add[0] = 1;
	p[6].b[0].add[1] = 2;
	p[6].b[0].add[2] = 1;
	p[6].b[0].dis[0] = 0;
	p[6].b[0].dis[1] = -1;
	p[6].b[0].dis[2] = -1;
	//61
	p[6].b[1].w = 2;
	p[6].b[1].add[0] = 2;
	p[6].b[1].add[1] = 2;
	p[6].b[1].dis[0] = 0;
	p[6].b[1].dis[1] = 1;
}
