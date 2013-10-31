#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxN = 400;
const double eps = 1e-8;

struct Point{
    double x, y;
    Point(){}
    Point(double x, double y):x(x), y(y){}
};
bool operator== ( const Point& A, const Point& B ){
    return ( fabs(A.x-B.x) <= eps && fabs(A.y-B.y) <= eps );
}
double operator * (const Point& A, const Point& B ){
    return A.x * B.x + A.y * B.y;
}

int N;
Point A[maxN], B[maxN];

double st[maxN], ed[maxN];

bool check( const Point& P, const Point& Q ){
    Point V;
    if ( P==Q ){
        V = Point( 0, 1 );
    }else{
        V = Point( P.y - Q.y, Q.x - P.x );
    }
    int i;
    double l = -1e20, r = 1e20;
    for ( i = 1; i<=N; i++ ){
        st[i] = A[i] * V;
        ed[i] = B[i] * V;
        if ( st[i] > ed[i] ) swap( st[i], ed[i] );
        if ( ed[i] + eps < l || 
             r + eps < st[i] ) return false;
        l >?= st[i];
        r <?= ed[i];
        if ( l > r + eps ) return false;
    }
    return true;
}

bool solve(){
    int i, j;
    for ( i = 1; i<=N; i++ ){
        if ( check( A[i], B[i] ) ) return true;
        for ( j = i+1; j<=N; j++ )
            if ( check( A[i], A[j] ) ||
                 check( A[i], B[j] ) ||
                 check( B[i], A[j] ) ||
                 check( B[i], B[j] ) )
                return true;
    }
    return false;
}

int main(){
    //freopen("segment.in","r",stdin);
    //freopen("segment.out","w",stdout);
    
    int T, i, j, k;
    scanf("%d", &T);
    while ( T-- ){
        scanf("%d", &N );
        for ( i = 1; i<=N; i++ )       
            scanf("%lf %lf %lf %lf", &A[i].x, &A[i].y, &B[i].x, &B[i].y );
        if ( solve() )
            printf("Yes\n"); else
            printf("No\n");
    }
}
