//https://oj.uz/submission/202009
#include <bits/stdc++.h>                                           
 
//#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define forev(i, b, a) for(int i = (b); i >= (a); --i)
#define forn(i, a, b) for(int i = (a); i <= (b); ++i)
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define s second
#define f first
 
 
using namespace std;
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;
typedef unsigned long long ull;         
typedef vector < pii > vpii;
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;                             
 
 
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 333;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const int inf = 1e9, maxn = 4e5 + 148, mod = 1e9 + 7, N = 1e5 + 11;
const db eps = 1e-12, pi = 3.14159265359;
const ll INF = 1e18;
 
inline int R () {
	char c;
	bool is_negative = 0, started = 0;
	int ans = 0;
	while (1) {
		c = getchar();
		if ((c > '9' || c < '0') && c != '-' && !started)
			continue;
		if ((c > '9' || c < '0') && c != '-' && started)
			break;
		started = 1;
		if (c == '-')
			is_negative = 1;
		else
			ans = ans * 10 + c - '0';
	}
 
	return ans;
}
 
int n, q, X[N], Y[N], res[N], szX, szY;
 
 
struct node {
	int x, y;
	bool operator < (const node &a) const {	
		return X[x] + Y[y] > X[a.x] + Y[a.y];
	}	
} d[N];
 
struct query {
	int a, b, c, id;
	bool operator < (const query &x) const {
		return c > x.c;
	}
} e[N];
 
struct ST {
	int tl, tr;
	ST *l, *r;
	int sum;
 
	ST () {}
	
	ST (int a, int b) {
		tl = a;
		tr = b;	
		sum = 0;
		l = r = NULL;
	}
 
	void update (int pos, int x) {
		if (tl == tr) {
			sum += x;
			return;
		}	
		int tm = (tl + tr) >> 1;
		if (pos <= tm) {
			if (!l)
				l = new ST(tl, tm);
			l->update(pos, x);
		} else {
			if (!r)
				r = new ST(tm + 1, tr);
			r->update(pos, x);
		}
 
		sum = (!l ? 0 : l->sum) + (!r ? 0 : r->sum);
	}
 
	int get (int lf, int rg) {
		if (lf > rg || tl > rg || lf > tr)	
			return 0;
		if (lf <= tl && tr <= rg)
			return sum;
		return (l ? l->get(lf, rg) : 0) + (r ? r->get(lf, rg) : 0);
	}
 
};
 
struct BIT {
	ST *T[N];
	
	BIT () {
		memset(T, 0, sizeof(T));
	}
 
	void add (int x, int y, int z) {
		x = N - 1 - x;
		while (x < N) {
			if (!T[x])
				T[x] = new ST(0, N - 1);				
			T[x]->update(y, z);
			x += x & -x;
		}	
	}
 
	int get (int x, int y) {
		x = N - 1 - x;
	    int res = 0;
		while (x > 0) {
			if (T[x]) 
				res += T[x]->get(y, N - 1);
			x -= x & -x;
		}	
		return res;
	}
} F;
 
 
 
 
 
main () {
//	file("");
	n = R(), q = R();
	forn (i, 1, n) {
		d[i].x = R();
		d[i].y = R();
		X[i] = d[i].x;
		Y[i] = d[i].y;
	}
 
	sort(X + 1, X + 1 + n);
	sort(Y + 1, Y + 1 + n);
	
	szX = unique(X + 1, X + 1 + n) - X - 1;
	szY = unique(Y + 1, Y + 1 + n) - Y - 1;
 
	forn (i, 1, n) {
		d[i].x = lower_bound(X + 1, X + 1 + szX, d[i].x) - X;
		d[i].y = lower_bound(Y + 1, Y + 1 + szY, d[i].y) - Y;
	}
 
 
 
	forn (i, 1, q) {
		e[i].a = R(); 
		e[i].b = R();	
		e[i].c = R();
		e[i].id = i;
		e[i].a = lower_bound(X + 1, X + 1 + szX, e[i].a) - X;
		e[i].b = lower_bound(Y + 1, Y + 1 + szY, e[i].b) - Y;
	}
 
	sort(d + 1, d + 1 + n);
	sort(e + 1, e + 1 + q);
 
	int j = 1;
	forn (i, 1, q) {
		while (j <= n && X[d[j].x] + Y[d[j].y] >= e[i].c) {
			F.add(d[j].x, d[j].y, 1);
//			cerr << " + " << d[j].x << ' ' << d[j].y << endl;
			++j;
		}
//		cerr << e[i].a << ' ' << e[i].b << " = " << get(e[i].a, e[i].b) << endl;
		res[e[i].id] = F.get(e[i].a, e[i].b);
	}
 
	forn (i, 1, q)
		printf("%d\n", res[i]);
}
