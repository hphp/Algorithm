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

int tc;
FILE *visualizer;
double maxx, minx, maxy, miny, mul;


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
void intersection_line_circle(pt c, double r, pt l1, pt l2, pt &p2)
{
	pt p = c;
	p.x += l1.y - l2.y;
	p.y += l2.x - l1.x;
	p = its(p, c, l1, l2);
	double d = dis(p,c), t = sqrt(r*r - d*d) / dis(l1,l2);
	p2.x = p.x + (l2.x-l1.x)*t;
	p2.y = p.y + (l2.y-l1.y)*t;
}

////////////////////////////////////////////////////


void mp_begin() {
    char s[30];
    tc++;
	sprintf(s, "Graphic_%d.mp", tc);
    visualizer = fopen(s, "w");
    assert(visualizer != NULL);
    fprintf(visualizer, "beginfig(1);\n");
    fprintf(visualizer, "u := 2cm;\n");
}

void mp_end() {
    fprintf(visualizer, "endfig;\n");
    fprintf(visualizer, "end\n");
    fclose(visualizer);
    char s[30];
	sprintf(s, "mpost Graphic_%d.mp", tc);	system(s);
	sprintf(s, "epstopdf Graphic_%d.1", tc);	system(s);
	sprintf(s, "del Graphic_%d.1", tc);		system(s);
	sprintf(s, "del Graphic_%d.log", tc);	system(s);
	sprintf(s, "del Graphic_%d.mp", tc);		system(s);
}

void mp_print_segment(pt a, pt b, const int& pen_width = 1, const string& color = "black") {
	a.x = -50 + 100.0 / (maxx - minx) * (a.x - minx);
	a.y = -50 + 100.0 / (maxy - miny) * (a.y - miny);
	b.x = -50 + 100.0 / (maxx - minx) * (b.x - minx);
	b.y = -50 + 100.0 / (maxy - miny) * (b.y - miny);

//	printf("%lf %lf - %lf %lf\n", a.x, a.y, b.x, b.y);
    fprintf(visualizer, "draw ");
    fprintf(visualizer, "(%.2lfu, %.2lfu) -- (%.2lfu, %.2lfu) withpen pencircle scaled %dpt withcolor %s;\n", a.x, a.y, b.x, b.y, pen_width, color.c_str());
}

//【注意】边太多的话会挂掉!最好一条边一条边自己画。 
void mp_print_polygon(const vector<pt>& p, const int& pen_width = 1, const string& color = "black") {
    fprintf(visualizer, "draw ");
    for (int i = 0; i < p.size(); ++i) {
        fprintf(visualizer, "(%.2lfu, %.2lfu) -- ", p[i].x, p[i].y);
    }
    fprintf(visualizer, "cycle withpen pencircle scaled %dpt withcolor %s;\n", pen_width, color.c_str());
}


void mp_print_point(pt a, const int& pen_width = 5, const string& color = "black") {
	a.x = -50 + 100.0 / (maxx - minx) * (a.x - minx);
	a.y = -50 + 100.0 / (maxy - miny) * (a.y - miny);

    fprintf(visualizer, "draw ");
    fprintf(visualizer, "(%.2lfu, %.2lfu) withpen pencircle scaled %dpt withcolor %s;\n", a.x, a.y, pen_width, color.c_str());
}

void mp_print_circle(pt a, double r, const int& pen_width = 1, const string& color = "black") {
	a.x = -50 + 100.0 / (maxx - minx) * (a.x - minx);
	a.y = -50 + 100.0 / (maxy - miny) * (a.y - miny);

	fprintf(visualizer, "draw ");
	fprintf(visualizer, "fullcircle scaled %.2lfu shifted (%.2lfu, %.2lfu) withpen pencircle scaled %dpt withcolor %s;\n", r * mul * 2, a.x, a.y, pen_width, color.c_str());
}

void mp_print_arc(const pt& a, const double& r, double s, double t, const int& pen_width = 1, const string& color = "black")
{
//	mp_print_circle(a, r);return;
	while (t - s < -eps)
	{
		t += PI * 2;
	}
	while (t - s - PI * 2 > -eps)
	{
		t -= PI * 2;
	}
//	printf("%lf %lf\n", s/PI*180, t/PI*180);
	pt last = pt(a.x + r * cos(s), a.y + r * sin(s)), now;
	double cur = s, del = (t - s) / 50;;
	while (cur < t)
	{
		cur += del;
		now = pt(a.x + r * cos(cur), a.y + r * sin(cur));
		mp_print_segment(last, now);
		last = now;
	}
}

/////////////////////////////////////////////////


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
	double vang, len, tmp;
	double l1, l2, l3, l4;

	vang = atan2(L2.y - L1.y, L2.x - L1.x);
	len = l1 = dis(L1, L2) < eps ? arcLength(a, b) : arcLength(a, vang) + dis(L1, L2) + arcLength(vang, b);
	
	if (2*R <= dis(L1, R2))
	{
	 	vang = atan2(R2.y - L1.y, R2.x - L1.x) + asin(2*R / dis(L1, R2));
		len = min(len, l2 = arcLength(a, vang) + sqrt((L1.x - R2.x)*(L1.x - R2.x) + (L1.y - R2.y)*(L1.y - R2.y) - 4 * R * R) + arcLength(b, vang));
	}
	
	if (2*R <= dis(L2, R1))
	{
	 	vang = atan2(L2.y - R1.y, L2.x - R1.x) - asin(2*R / dis(L2, R1));
		len = min(len, l3 = arcLength(vang, a) + sqrt((L2.x - R1.x)*(L2.x - R1.x) + (L2.y - R1.y)*(L2.y - R1.y) - 4 * R * R) + arcLength(vang, b));
	}
	
	vang = atan2(R2.y - R1.y, R2.x - R1.x);
	len = min(len, l4 = dis(R1, R2) < eps ? arcLength(b, a) : arcLength(vang, a) + dis(R1, R2) + arcLength(b, vang));
	
	if (len == l1)
	{
//		puts("-1-");
//		printf("L1: %lf %lf\n", L1.x, L1.y);
//		printf("L2: %lf %lf\n", L2.x, L2.y);
		if (dis(L1, L2) < eps)
		{
			mp_print_arc(L1, R, a-PI/2.0, b-PI/2.0);
		}
		else
		{
			tmp = atan2(L2.y - L1.y, L2.x - L1.x) - PI / 2.0;
			mp_print_segment(L1 + pt(cos(tmp), sin(tmp))*R, L2 + pt(cos(tmp), sin(tmp))*R);
			mp_print_arc(L1, R, a-PI/2.0, tmp);
			mp_print_arc(L2, R, tmp, b-PI/2.0);
		}
	}
	else if (len == l2)
	{
//		puts("-2-");
		tmp = atan2(R2.y - L1.y, R2.x - L1.x) + asin(2*R / dis(L1, R2));
		mp_print_segment(L1 + pt(cos(tmp-PI/2.0), sin(tmp-PI/2.0))*R, R2 + pt(cos(tmp+PI/2.0), sin(tmp+PI/2.0))*R);
		mp_print_arc(L1, R, a-PI/2.0, tmp-PI/2.0);
		mp_print_arc(R2, R, b+PI/2.0, tmp+PI/2.0);
	}
	else if (len == l3)
	{
//		puts("-3-");
	 	tmp = atan2(L2.y - R1.y, L2.x - R1.x) - asin(2*R / dis(L2, R1));
		mp_print_segment(R1 + pt(cos(tmp+PI/2.0), sin(tmp+PI/2.0))*R, L2 + pt(cos(tmp-PI/2.0), sin(tmp-PI/2.0))*R);
		mp_print_arc(R1, R, tmp+PI/2.0, a+PI/2.0);
		mp_print_arc(L2, R, tmp-PI/2.0, b-PI/2.0);
	}
	else
	{
//		puts("-4-");
		if (dis(R1, R2) < eps)
		{
			mp_print_arc(R1, R, b+PI/2.0, a+PI/2.0);
		}
		else
		{
			tmp = atan2(R2.y - R1.y, R2.x - R1.x) + PI/2.0;
			mp_print_segment(R1 + pt(cos(tmp), sin(tmp))*R, R2 + pt(cos(tmp), sin(tmp))*R);
			mp_print_arc(R1, R, tmp, a+PI/2.0);
			mp_print_arc(R2, R, b+PI/2.0, tmp);
		}
	}
	return len;
}		

double end_length(pt O, pt A, double a)
{
	bool r = 0;
	pt B = A + pt(cos(a), sin(a));
	if (cpr(O, A, B) > 0)
	{
		r = 1;
		a = PI - a;
		A.x = -A.x;
		O.x = -O.x;
	}
	pt C = A + pt(sin(a), -cos(a)) * R;
	double D = dis(O, C);
	
	if (fabs(D - R) < eps)
	{
		double aa = a + PI/2.0;
		double bb = atan2(O.y - C.y, O.x - C.x);
		if (!r)
			mp_print_arc(C, R, aa, bb);
		else
		{
			O.x = -O.x;
			C.x = -C.x;
			mp_print_arc(C, R, PI-bb, PI - aa);
			C.x = -C.x;
			O.x = -O.x;
		}
		return arcLength(a, atan2(O.y - C.y, O.x - C.x) - PI / 2.0);
	}
	else if (D - R > eps)
	{
//		puts("out"); 
		double tmp = atan2(C.y - O.y, C.x - O.x) + asin(R / D) + PI/2.0;
		pt X = pt(C.x + R*cos(tmp), C.y + R*sin(tmp)); 
		if (!r)
		{
			mp_print_segment(O, X);
			mp_print_arc(C, R, a + PI/2.0, tmp);
		}
		else
		{
			X.x = -X.x;
			C.x = -C.x;
			O.x = -O.x;
			mp_print_segment(O, X);
			mp_print_arc(C, R, PI - tmp, PI/2.0 - a);
			X.x = -X.x;
			C.x = -C.x;
			O.x = -O.x;
		}
		return sqrt(D*D - R*R) + arcLength(a, atan2(C.y - O.y, C.x - O.x) + asin(R / D));
	}
	else
	{
//		puts("in"); 
		intersection_line_circle(C, R, O, O + pt(cos(a), sin(a)), B);
		D = dis(B, O);
		double D1 = 2 * PI * R + D - arcLength(atan2(B.y - C.y, B.x - C.x) - PI / 2.0, a);
		pt CC = C + O - B;
		double aa = a+PI/2.0;
		double bb = atan2(B.y - C.y, B.x - C.x);
		if (!r)
		{
			mp_print_arc(CC, R, aa, bb);
			mp_print_segment(A, pt(A.x-D*cos(a), A.y-D*sin(a)));
		}
		else
		{
			A.x = -A.x;
			CC.x = -CC.x;
			mp_print_arc(CC, R, PI-bb, PI-aa);
			mp_print_segment(A, pt(A.x-D*cos(PI-a), A.y-D*sin(PI-a)));
			CC.x = -CC.x;
			A.x = -A.x;
		}
		C = A + A - C;
		D = dis(O, C);
		double D2 = sqrt(D*D - R*R) + arcLength(atan2(C.y - O.y, C.x - O.x) - asin(R / D), a);
		if (D1 > D2) while (1);
		return min(D1, D2);
	}
}


double solve()
{
	mp_begin();
	mp_print_point(S, 40, "black");
	mp_print_point(A, 40, "red");
	mp_print_point(B, 40, "green");
	mp_print_point(T, 40, "blue");
	double ans1 = end_length(S, A, angA) + mid_length(A, B, angA, angB) + end_length(T, B, angB + PI);
	mp_end();

	mp_begin();
	mp_print_point(S, 40, "black");
	mp_print_point(A, 40, "red");
	mp_print_point(B, 40, "green");
	mp_print_point(T, 40, "blue");
	double ans2 = end_length(S, B, angB) + mid_length(B, A, angB, angA) + end_length(T, A, angA + PI);
	mp_end();

//	printf("%lf %lf %lf\n", end_length(S, A, angA), mid_length(A, B, angA, angB), end_length(T, B, angB + PI));
//	printf("%lf %lf %lf\n", end_length(S, B, angB), mid_length(B, A, angB, angA), end_length(T, A, angA + PI));
//	printf("%lf %lf\n", ans1, ans2);
	return min(ans1, ans2);
}

double f()
{
	double d = dis(S, T);
	pt SS, TT;
	SS.x = -50 + 100.0 / (maxx - minx) * (S.x - minx);
	SS.y = -50 + 100.0 / (maxy - miny) * (S.y - miny);
	TT.x = -50 + 100.0 / (maxx - minx) * (T.x - minx);
	TT.y = -50 + 100.0 / (maxy - miny) * (T.y - miny);
	return dis(SS, TT) / d;
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
		
		minx = min(min(A.x, B.x), min(S.x, T.x)) - 5*R;
		maxx = max(max(A.x, B.x), max(S.x, T.x)) + 5*R;
		miny = min(min(A.y, B.y), min(S.y, T.y)) - 5*R;
		maxy = max(max(A.y, B.y), max(S.y, T.y)) + 5*R;
		if (maxy - miny > maxx - minx)
			maxx = minx + maxy - miny;
		else	
			maxy = miny + maxx - minx;
		mul = f();

		printf("%.2lf\n", solve());
	}
	return 0;
}
