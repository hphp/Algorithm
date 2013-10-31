#include <iostream>
#include <stdio.h>
#include <cmath>
#include <queue>
#define H 1001009
#define W 1001008
using namespace std;
struct point { int x, y; };
struct rect { point p1, p2; int c; };//c表颜色
int area(rect r) {//求面积
    return (r.p2.x-r.p1.x)*(r.p2.y-r.p1.y);
}
int price[4];
int tt=1;
struct cutRect {
public:
    queue<rect> Q;
    rect nil;
    cutRect() { nil.c = -1; }
    void add(rect r) {//加点
        Q.push(r);
    }
    void cut(rect r1, rect r2) {//两个矩形的切割
        if(r2.p2.x <= r1.p1.x || r2.p2.y <= r1.p1.y
            || r2.p1.x >= r1.p2.x || r2.p1.y >= r1.p2.y) {
            add(r2);
            return;
        }

        rect rt = r2;
        if(r2.p2.x > r1.p2.x ) {
            rt.p1.x = r1.p2.x, rt.p1.y = r2.p1.y, rt.p2 = r2.p2;
            r2.p2.x = r1.p2.x;
				rt.c = r2.c;
            add(rt);
        }
        if(r2.p1.x < r1.p1.x ) {
            rt.p1 = r2.p1, rt.p2.y = r2.p2.y, rt.p2.x = r1.p1.x;
            r2.p1.x = r1.p1.x;
				rt.c = r2.c;
            add(rt);
        }
        if(r2.p1.y < r1.p1.y ) {
            rt.p1 = r2.p1, rt.p2.y = r1.p1.y, rt.p2.x = r2.p2.x;
            r2.p1.y = r1.p1.y;
				rt.c = r2.c;
            add(rt);
        }
        if(r2.p2.y > r1.p2.y ) {
            rt.p2 = r2.p2, rt.p1.x = r2.p1.x, rt.p1.y = r1.p2.y;
            r2.p2.y = r1.p2.y;
				rt.c=r2.c;
            add(rt);
        }
    }
    void cut(rect rt) {//加入一个矩形对所有已有举行切割
        Q.push(nil);
        while(!Q.empty()) {
            rect rp = Q.front(); Q.pop();
            if(rp.c == -1) break;
            cut(rt, rp);
        }
        Q.push(rt);
    }
    void pro() {//统计各颜色的面积
        //int cnum[2600]; memset(cnum, 0, sizeof(cnum));
        rect rp;
		int sum = 0;
        while(!Q.empty()) {
            rp = Q.front(); Q.pop();
            sum += rp.c*area(rp);
        }
      /*  for(int i=0; i<2501; i++)
            if(cnum[i])
                printf("%d %d\n", i, cnum[i]);*/
		printf("\n",tt++);
	printf("%d\n",sum);
    }
}C;
int main()
{
 //   freopen("rect1.in", "r", stdin);
  //  freopen("rect1.out", "w", stdout);
	int test;
	scanf("%d",&test);
	while(test--)
{
 //   int W, H, n;
	int n;
    rect rt;
	 int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&price[i]);
 //   scanf("%d%d%d", &W, &H, &n);
    rt.p1.x = rt.p1.y = 0;
    rt.p2.x = W, rt.p2.y = H, rt.c = 0;
    C.add(rt);
    for(int i=0; i<n; i++) {
	int c;
        scanf("%d%d%d%d%d", &rt.p1.x, &rt.p1.y, &rt.p2.x, &rt.p2.y, &c);
		rt.c = price[c];
        C.cut(rt);
    }
    C.pro();
}
    return 0;
}
