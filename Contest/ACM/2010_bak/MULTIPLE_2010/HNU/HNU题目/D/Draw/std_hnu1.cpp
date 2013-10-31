#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

#define DEBUG 1

using namespace std;

const double eps = 1e-8;
const int N = 105;
const double PI = acos(-1);
const double inf = 1e6;

inline int sig( double x ){
    return (x > eps) - (x < - eps);
}

struct point {
	double x, y;
	point(double _x = 0, double _y = 0) {
		x = _x;
		y = _y;
	}
	double dis(point a) {
		return sqrt( (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y) );
	}
	void read() {
		scanf("%lf %lf", &x, &y);
	}
	void write() {
		printf("%.4lf %.4lf\n", x, y);
	}
	void get(double a, double b) {
		x = a;
		y = b;
	}
	point operator+(const point a)const {
		point ret;
		ret.x = x + a.x;
		ret.y = y + a.y;
		return ret;
	}
};

inline double xmul(point sp, point ep, point op) {
	return ((sp.x-op.x)*(ep.y-op.y) - (ep.x-op.x)*(sp.y-op.y));
}

inline double xmul1(point a, point b, point c) {
	return (c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x);
}

inline double cross(point a, point b) {
	return a.x*b.y - a.y * b.x;
}

inline double area(point p[], int n) {
	double sum = 0;
	p[n] = p[0];
	for(int i = 0; i < n; i ++) {
		sum += cross(p[i],p[i+1]);
	}
	return sum / 2;
}

point intersection( point u1, point u2, point v1, point v2) {
	point ret = u1;
	double t = ((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
			   ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
	ret.x += (u2.x-u1.x) * t;
	ret.y += (u2.y-u1.y) * t;
	return ret;
	
}
inline bool cmp(point a, point b) {
	if ( a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}

void tubao(point p[], int id[], int n, int &top) {
	sort(p, p + n, cmp);
	int cnt = 1;
	for(int i = 1; i < n; i ++) 
	if( p[i].x != p[i-1].x || p[i].y != p[i-1].y) p[cnt ++] = p[i];
	n = cnt;
	if( n <= 1 ) {
		top = 0;
		return ;
	}
	top = 1;
	id[0] = 0; id[1] = 1;
	for(int i = 2; i < n; i ++) {
		while( top >= 1 && xmul(p[id[top-1]],p[id[top]],p[i])<=0) top --;
		id[++top] = i;
	}
	int tp = top;
	id[++top] = n - 2;
	for(int i = n - 3; i >= 0; i --) {
		while( top >= tp + 1 && xmul(p[id[top-1]], p[id[top]],p[i])<=0) top --;
		id[++top] = i;
	}
	if( top > n) top = n;
}

point ini[N], des[N];
point A[N], B[N], C[N+N],  dir;
double d, r;
int n, m;

void read() {
	for(int i = 0; i < n; i ++) ini[i].read();
	scanf("%d", &m);
	for(int i = 0; i < m; i ++) des[i].read();
	scanf("%lf %lf", &r, &d);
}



void pre(point p[],int n) {
	point tp[N];
	if( area(p, n)  < 0 )  {
		for(int i = 0; i < n; i ++) tp[i] = p[n - 1 - i];
		for(int i = 0; i < n; i ++) p[i] = tp[i];
	}
}

// p ÇÐ po 
void solve(point p[], point po[], int n, int m, point q[], int &L) {
	int i, j, flag, tlen;
	double sum;
	point tp[N+N], tt[N+N], ns, ne;
	point s, e, pp;
	pre(A, n);
	pre(B, m);
	for(i = 0; i < m; i ++) tp[i] = po[i];
	int len = m;
	A[n] = A[0];
	for(i = 0; i < n; i ++) {
		s = p[i];  e = p[i + 1];
		tlen = 0;
		tp[len] = tp[0];
		for(j = 0; j < len; j ++) {
			ns = tp[j]; ne = tp[j + 1];
			if( xmul1(s, e, ns) < eps) tt[tlen++] = ns;
			if( xmul1(s, e, ns) * xmul1(s, e, ne) < - eps ) {
				pp = intersection(s, e, ns, ne);
				tt[tlen++] = pp;
			}
		}
		for(j = 0; j < tlen; j ++) tp[j] = tt[j];
		len = tlen;
	}
	L = len;
	for(i = 0; i < L; i ++) q[i] = tp[i];
}

int change(double r, double mid) {
	int id[N], len, cnt = 0;
	for(int i = 0; i < n; i ++) A[i] = ini[i];
	for(int i = 0; i < m; i ++) B[i] = des[i];
	dir.get( cos(r/180*PI)*mid, sin(r/180*PI)*mid );
	for(int i = 0; i < m; i ++) {
		C[i] = B[i];
		C[m+i] = B[i] + dir;
		cnt += 2;
	}
	tubao(C, id, cnt, len);
	
	for(int i = 0; i <= len; i ++) B[i] = C[id[i]];
	return len;
}

double work(point p[], double r, double mid) {
	int mt = change(r, mid);
	int L = 0;
	point now[N];
	solve(A, B, n, mt, now, L);
	double sum = fabs(area(now, L));
	if( !DEBUG ) {	
		//for(int i = 0; i < n; i ++) A[i].write(); puts("");
		for(int i = 0; i < mt; i ++) B[i].write(); puts("");
		for(int i = 0; i < L; i ++) now[i].write();puts("");
		//printf("%lf\n", fabs(area(A,n)));
		system("pause");
	}
	return sum;
}

void go() {
	double ans = 0;
    double dest = fabs(area(ini, n)) * (1.0 - d);
    if ( sig( work( B, r, inf ) - dest ) < 0 ){
        printf("-1\n");
        return;
    }
    double left = 0, right = 20000;
    while( sig( left - right ) != 0 ){
        double mid = (left + right) / 2.0;
		if( !DEBUG ) printf("t = %lf mid = %.4lf \n",dest, mid);
        double temp = work( B, r, mid );
        if ( sig(  temp - dest  ) < 0 )
            left = mid;
        else
            right = mid;
    }
    printf("%.4lf\n",left);
}

int main() {
	freopen("1.std.in","r",stdin);
	freopen("2.std.out","w",stdout);
	while( scanf("%d", &n) != EOF) {
		read();
		go();
	}
}
