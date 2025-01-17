#include <stdio.h>
#include <bits/stdc++.h>
 
using namespace std;
 
typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;
 
typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;
 
typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;
 
#define F first
#define S second
 
#define en end()
#define bg begin()
 
#define rev reverse
#define mp make_pair
#define pb push_back
 
#define y1 y1234567890
#define um unordered_map
 
#define all(x) x.bg, x.en
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)
 
#define sqr(x) ((x + 0ll) * (x))
#define sqrd(x) ((x + 0.0) * (x))
 
#define forn(i, n) for (int i = 1; i <= n; i++)
 
const ll inf = (ll)1e18;
const ll mod = (ll)1e9 + 7;
 
const db eps = (db)1e-9;
const db pi = acos(-1.0);
 
const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};
 
const int N = 300500;
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
struct node {
	int pr, sz;
	ll key, sum;
	node *l, *r;
	node(){};
	node(ll x) {
		sz = 1;
		key = sum = x;
		pr = rnd();
		l = r = NULL;
	}
};
 
node *root = NULL;
 
typedef pair < node*, node* > pnn;
 
inline int getsz(node *v) {
	return (v ? v->sz : 0);
}
 
inline ll getsum(node *v) {
	return (v ? v->sum : 0);
}
 
inline void upd(node *v) {
	if (!v) return;
	v->sz = getsz(v->l) + getsz(v->r) + 1;
	v->sum = getsum(v->l) + getsum(v->r) + v->key;
}
 
pnn split(node *v, int x) {
	if (!v) return {v, v};
	pnn res;
	if (v->key <= x) {
		res = split(v->r, x);
		v->r = res.F;
		res.F = v;
	}
	else {
		res = split(v->l, x);
		v->l = res.S;
		res.S = v;
	}
	upd(res.F);
	upd(res.S);
	return res;
}
 
node* merge(node *a, node *b) {
	if (!a) return b;
	if (!b) return a;
	if (a->pr > b->pr) {
		a->r = merge(a->r, b);
		upd(a);
		return a;
	}
	else {
		b->l = merge(a, b->l);
		upd(b);
		return b;
	}
}
 
node* er(node *v) {
	if (v->r)
		v->r = er(v->r);
	else
		v = merge(v->l, v->r);
	upd(v);
	return v;
}
 
void dfs(node *v) {
	if (!v) return;
	dfs(v->l);
	cerr << v->key << " ";
	dfs(v->r);
}
 
ll sum;
int cnt_a, cnt_b;
multiset < int > s;
int n, m, a[N], b[N];
 
int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);
 
	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
 
	//cout << setprecision(10) << fixed;
	
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s.insert(a[i]);
		sum += a[i];
		cnt_a += (a[i] > 0);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		cnt_b += (b[i] > 0);
	}
 
	for (int i = 1; i <= m; i++)
		root = merge(root, new node(b[i]));
 
	int q;
	scanf("%d", &q);
	while (q--) {
		int tp, pos;
		scanf("%d %d", &tp, &pos);
		if (tp <= 2) {
			s.erase(s.find(a[pos]));
			cnt_a -= (a[pos] > 0);
			sum -= a[pos];
 
			a[pos] += (tp == 1 ? 1 : -1);
 
			s.insert(a[pos]);
			cnt_a += (a[pos] > 0);
			sum += a[pos];
		}
		else {
			cnt_b -= (b[pos] > 0);
 
			pnn p = split(root, b[pos]);
			p.F = er(p.F);
			root = merge(p.F, p.S);
 
			b[pos] += (tp == 3 ? 1 : -1);
 
			cnt_b += (b[pos] > 0);
			
			p = split(root, b[pos]);
			root = merge(merge(p.F, new node(b[pos])), p.S);
		}

		int ok = ((*s.rbegin()) <= cnt_b);
		pnn p = split(root, cnt_a);
		ll val = getsum(p.F) + getsz(p.S) * 1ll * cnt_a;
		root = merge(p.F, p.S);
		ok &= (val >= sum);
		printf("%d\n", ok);
	}
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;
 
	return 0;
}