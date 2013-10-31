#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string>
#define MAXV 2000
#define PI 3.14159265358979323846
#define eps 1e-8
#define zero(x) (fabs(x)<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
using namespace std;


//二维点
struct pt
{
	double x, y;
	pt(){}
	pt(double _x, double _y)
	{
		x = _x;
		y = _y;
	}
	pt operator - (const pt p1){return pt(x - p1.x, y - p1.y);}
	pt operator + (const pt p1){return pt(x + p1.x, y + p1.y);}
	pt operator / (double r){return pt(x / r, y / r);}
	pt operator * (double r){return pt(x * r, y * r);}
	bool operator == (const pt p1)const{return fabs(x-p1.x)<eps && fabs(y-p1.y)<eps;}
	bool operator != (const pt p1)const{return fabs(x-p1.x)>eps || fabs(y-p1.y)>eps;}
	bool operator < (const pt p1)const{return y < p1.y-eps || y < p1.y+eps && x < p1.x;}
	
	void read(){
		scanf("%lf %lf", &x, &y);
	}
};

double dis(const pt &a, const pt &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
double cpr(const pt &a,const pt &b,const pt &c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}

//求直线ab和直线cd的交点
pt its(const pt &a, const pt &b, const pt &c, const pt &d)
{
	pt ret = a;
	double t =  ((c.x - a.x)*(d.y - c.y) - (c.y - a.y)*(d.x - c.x))/
				((b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x));
	ret.x += (b.x - a.x) * t;
	ret.y += (b.y - a.y) * t;
	return ret;
}

//计算直线与圆的交点,保证直线与圆有交点
//计算线段与圆的交点可用这个函数后判点是否在线段上
void intersection_line_circle(pt c, double r, pt l1, pt l2, pt &p1, pt &p2)
{
	pt p = c;
	p.x += l1.y - l2.y;
	p.y += l2.x - l1.x;
	p = its(p, c, l1, l2);
	double d = dis(p,c), t = sqrt(r*r - d*d) / dis(l1,l2);
	p2.x = p.x + (l2.x-l1.x)*t;
	p2.y = p.y + (l2.y-l1.y)*t;
	p1.x = p.x - (l2.x-l1.x)*t;
	p1.y = p.y - (l2.y-l1.y)*t;
}

////////////////////////////////////////////////////

double R, angA, angB;
pt S, A, B, T;

double arcLength(double s, double t)
{
	double res = t - s;
	while (res < -eps)
		res += 2*PI;
	while (res - 2*PI > -eps)
		res -= 2*PI;
	return res * R;
}

double mid_length(pt A, pt B, double a, double b)
{
	pt L1 = A + pt(-sin(a), cos(a)) * R;
	pt L2 = B + pt(-sin(b), cos(b)) * R;
	pt R1 = A + pt(sin(a), -cos(a)) * R;
	pt R2 = B + pt(sin(b), -cos(b)) * R;
	double vang, len;

	vang = atan2(L2.y - L1.y, L2.x - L1.x);
	len = dis(L1, L2) < eps ? arcLength(a, b) : arcLength(a, vang) + dis(L1, L2) + arcLength(vang, b);
	
	if (2*R <= dis(L1, R2))
	{
	 	vang = atan2(R2.y - L1.y, R2.x - L1.x) + asin(2*R / dis(L1, R2));
		len = min(len, arcLength(a, vang) + sqrt((L1.x - R2.x)*(L1.x - R2.x) + (L1.y - R2.y)*(L1.y - R2.y) - 4 * R * R) + arcLength(b, vang));
	}
	
	if (2*R <= dis(L2, R1))
	{
	 	vang = atan2(L2.y - R1.y, L2.x - R1.x) - asin(2*R / dis(L2, R1));
		len = min(len, arcLength(vang, a) + sqrt((L2.x - R1.x)*(L2.x - R1.x) + (L2.y - R1.y)*(L2.y - R1.y) - 4 * R * R) + arcLength(vang, b));
	}
	
	vang = atan2(R2.y - R1.y, R2.x - R1.x);
	len = min(len, dis(R1, R2) < eps ? arcLength(b, a) : arcLength(vang, a) + dis(R1, R2) + arcLength(b, vang));
	
	return len;
}		

double end_length(pt O, pt A, double a)
{
	pt B = A + pt(cos(a), sin(a));
	if (cpr(O, A, B) > 0)
	{
		a = PI - a;
		A.x = -A.x;
		O.x = -O.x;
	}
	pt C = A + pt(sin(a), -cos(a)) * R;
	double D = dis(O, C);
	
	if (fabs(D - R) < eps)
	{
		return arcLength(a, atan2(O.y - C.y, O.x - C.x) - PI / 2.0);
	}
	else if (D - R > eps)
	{
		return sqrt(D*D - R*R) + arcLength(a, atan2(C.y - O.y, C.x - O.x) + asin(R / D));
	}
	else
	{
		intersection_line_circle(C, R, O, O + pt(cos(a), sin(a)), B, B);
		double D1 = 2 * PI * R + dis(B, O) - arcLength(atan2(B.y - C.y, B.x - C.x) - PI / 2.0, a);
		C = A + A - C;
		D = dis(O, C);
		double D2 = sqrt(D*D - R*R) + arcLength(atan2(C.y - O.y, C.x - O.x) - asin(R / D), a);
		if (D1 > D2) while (1);
		return min(D1, D2);
	}
}


double solve()
{
	double ans1 = end_length(S, A, angA) + mid_length(A, B, angA, angB) + end_length(T, B, angB + PI);
	double ans2 = end_length(S, B, angB) + mid_length(B, A, angB, angA) + end_length(T, A, angA + PI);
//	printf("%lf %lf %lf\n", end_length(S, A, angA), mid_length(A, B, angA, angB), end_length(T, B, angB + PI));
//	printf("%lf %lf %lf\n", end_length(S, B, angB), mid_length(B, A, angB, angA), end_length(T, A, angA + PI));
//	printf("%lf %lf\n", ans1, ans2);
	return min(ans1, ans2);
}

int main()
{
	double dx, dy;
	while (~scanf("%lf", &R))
	{
		S.read();
		A.read();
		scanf("%lf %lf", &dx, &dy);
		angA = atan2(dy, dx);
		B.read();
		scanf("%lf %lf", &dx, &dy);
		angB = atan2(dy, dx);
		T.read();
		printf("%.2lf\n", solve());
	}
	return 0;
}
