#include<iostream>
#include<ctime>
using namespace std;

typedef long long LL;

const int maxn = 100005;
bool ss[maxn] = {1,1};
int pp[maxn >> 1],plen = 0;
int fac[32][2],flen ;
int F[maxn],Inv[maxn],DP[maxn << 1];
int n,k,m;

LL cnt_of_p;
int p,P;
int gcd(int a, int b){return b? gcd(b,a % b): a;}

void mklist(){
	int i,j;
	for(i = 2; i * i < maxn; ++ i) if(! ss[i]) for(j = i; j * i < maxn; ++ j) ss[i * j] = 1;
	for(i = 2; i < maxn; ++ i) if(! ss[i]) pp[plen ++]  =  i;
}

void split(int n){
	flen= 0;
	int i;
	for(i = 0; i < plen && pp[i] <= n; ++ i){
		if(n % pp[i]) continue;
		fac[flen][0] = pp[i];
		fac[flen][1] = 0;
		while(n % pp[i] == 0) n/= pp[i], ++ fac[flen][1];
		++ flen;
	}
	if(n != 1){
		fac[flen][0] = n;
		fac[flen ++][1] = 1;
	}
}
int mod(LL a,int b,int c){
	LL ret = 1 % c; 
	while(b){
		if(b&0x1) ret= ret * a % c;
		a = a * a % c;
		b >>=1;
	}
	return ret;
}

int InvMod(int x){return mod(x,P - P / p - 1, P);}
LL cal_cnk_mod_pk(LL n,LL k,LL P,LL p){ // P = p^i... i >= 1
	LL ans = 1,i,cnt_of_p = 0;
	for(i = 1; i <= k; ++ i){
		LL tmp = n - i + 1;
		while(tmp % p == 0) tmp /= p,++ cnt_of_p;
		ans = ans * tmp % P;
		tmp = i;
		while(tmp % p == 0) tmp /= p, -- cnt_of_p;
		ans = ans * InvMod(tmp) % P;
	}
	ans = ans * mod((LL)p,cnt_of_p,P) % P;
	return ans;
}

void init(){
	F[0] = Inv[0] = 1;cnt_of_p = 0;
	int i,tmp;
	for(i = 1; i < P; ++ i){
		F[i] = F[i - 1];Inv[i] = Inv[ i - 1];
		if(gcd(i,p) == 1) F[i] = (LL)F[i] * i % P,Inv[i] = (LL)Inv[i] * InvMod(i) % P;
	}
}

int cal_fac_modP(int n){//(1 * 2 * 3 * ... * n) mod P, P = p ^ cntk
	if(n <= 1) return 1;
	LL ans = 1;
	int cnt_of_seg = n / P,cnt_of_rem = n % P;
	ans = mod(F[P - 1], cnt_of_seg, P);
	ans = ans * F[cnt_of_rem] % P;
	cnt_of_p += n /= p;
	ans = ans * cal_fac_modP(n ) % P;
	return ans;
}

int cal_inv_modP(int n){//Inv(1 * 2 * 3 * ... * n) mod P, P = p ^ cntk
	if(n <= 1) return 1;
	LL ans = 1;
	int cnt_of_seg = n / P,cnt_of_rem = n % P;
	ans = mod(Inv[P - 1], cnt_of_seg, P);
	ans = ans * Inv[cnt_of_rem] % P;
	cnt_of_p -= n /= p;
	ans = ans * cal_inv_modP(n ) % P;
	return ans;
}
int ext_gcd(int a, int b, int &x, int &y){
	int t, d;
	if (b == 0) { x = 1; y = 0; return a; }
	d = ext_gcd(b, a % b, x, y);
	t = x;
	x = y;
	y = t - a / b*y;
	return d;
}
int CTR(int b[], int w[], int k) {
	int i;
	int d, x, y, a = 0, m, n = 1;
	for (i = 0; i < k; i++) n *= w[i];
	for (i = 0; i < k; i++) {
		m = n / w[i];
		d = ext_gcd(w[i], m, x, y);
		LL yy = y; yy = yy * m % n; yy = yy * b[i] % n;
		a = (a + yy) % n;
	}
	if (a >= 0) return a;
	else return (a + n);
}

int Cal_Cnk_mod_P_K(int n,int k,int _p,int _P){
	p = _p;
	P = _P;
	init();
	LL ans = cal_fac_modP(n);
	ans = ans * cal_inv_modP(k)% P;
	ans = ans * cal_inv_modP(n - k)% P;
	ans = ans * mod(p,cnt_of_p,P) % P;
	return ans ;
}

int cc = 0;
int b[55],w[55];
int idx = 0;
void work(){
	++ idx;
	printf("Case %d: ",idx);
	k = n - k;
	int i,j;
	for(i = 0; i < flen; ++ i){
		w[i] = 1;
		for(j = 0; j < fac[i][1]; ++ j) w[i] *= fac[i][0];
		b[i] = Cal_Cnk_mod_P_K(n,k,fac[i][0],w[i]);
		//printf("x = %d (mod %d) \n",b[i],w[i]);
		//printf("brute_forece_x = %lld\n",cal_cnk_mod_pk(n,k,w[i],fac[i][0]));
	}
	LL ans = CTR(b,w,flen);
	int cnt_of_seg,cnt_of_rem;
	DP[0] = 1; DP[1] = 0;
	for(i = 2; ; ++ i){
		DP[i] = (LL)(i - 1) * (DP[i - 1] + DP[i - 2]) % m;
		if(DP[i] == 2 && DP[i - 1] == 1 && i != 3){
			cnt_of_seg = i - 3;
			break;
		}
	}
	if(k == 0){
		puts("1");
		return ;
	}	
	if(k == 1) {
		puts("0");
		return ;
	}
	cnt_of_rem = (k - 1) % cnt_of_seg;
	if(cnt_of_rem == 0) cnt_of_rem = cnt_of_seg;
	ans = ans * DP[cnt_of_rem + 1] % m;
	printf("%I64d\n",ans);
	/*cout <<"AC_suan_zhi === " <<  DP[cnt_of_rem + 1]  <<endl;
	int A,B,C; A = 1; B = 0;
	for(i = 2; i <= k; ++ i){
		C = (LL)(i - 1) * (A + B) % m;
		A = B;
		B = C;
	}
	cout <<"baoli_cuopai_zhi === " <<  B  <<endl;*/
}

void get(){scanf("%d%d%d",&n,&k,&m);}
int main(){
	/*
	Data_gen:
	srand(time(NULL));
	freopen("D:\\in.txt","w",stdout);
	int T = 4000;
	printf("%d\n",T);
	while(T --){
		int n,k,m;
		n  = rand() % 10000 + 1;
		n *= rand() % 10000 + 1;
		n *= rand() % 10 + 1;
		k = rand() % 10000 + 1;
		k *= rand() % 10000 + 1;
		k *= rand() % 10 + 1;
		if( n < k) swap(n,k);
		k = (T >= 355 && T <= 356) ? 0 : k;
		m = rand() % 10000 + 1;
		m *= rand() % 10 + 1;
		while( m < 10) m += rand() % 10000 + 1;
		printf("%d %d %d\n",n,k,m);
	}*/
	/*
	Input_Check:
	freopen("D:\\in.txt","r",stdin);
	int T;
	cin >> T;
	while(T --){
		int n,m,k;
		cin >> n >> k >> m;
		if(!( n >= 1 && n <= 1000000000)) puts("SB!");
		if(!(k >= 0 && k <= n)) puts("SB!!");
		if(!(m >= 10 && m <= 100000)) puts("SB!!!");
	}
	puts("orz");*/
	
	//freopen("D:\\in.txt","r",stdin);
	//freopen("D:\\out2.txt","w",stdout);
	mklist();
	int T;
	scanf("%d",&T);
	while(T --){
		get();
		split(m);
		work();
	}
	//cout <<clock() <<"ms "<<endl;
	return 0;
}