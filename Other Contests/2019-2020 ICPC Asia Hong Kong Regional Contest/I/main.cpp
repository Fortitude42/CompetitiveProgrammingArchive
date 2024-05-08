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

const int N = 200500;

bool u[N];
vector < int > ans;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	int key, pr, id;
	ll keep;
	node *l, *r;
	node(){};
	node(int x, int y) {
		key = x;
		pr = rnd();
		id = y;
		keep = 0;
		l = r = NULL;
	}
};

node *root[N];

typedef pair < node*, node* > pnn;

inline void push(node *v) {
	if (!v) return;
	if (v->l) {
		v->l->key += v->keep;
		v->l->keep += v->keep;
	}
	if (v->r) {
		v->r->key += v->keep;
		v->r->keep += v->keep;
	}
	v->keep = 0;
}

pnn split(node *v, int x) {
	if (!v) return {v, v};
	push(v);
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
	//upd(res.F);
	//upd(res.S);
	return res;
}

node* merge(node *a, node *b) {
	push(a);
	push(b);
	if (!a) return b;
	if (!b) return a;
	if (a->pr > b->pr) {
		a->r = merge(a->r, b);
		//upd(a);
		return a;
	}
	else {
		b->l = merge(a, b->l);
		//upd(b);
		return b;
	}
}

void dfs(node *v) {
	if (!v) return;
	dfs(v->l);
	if (!u[v->id]) {
		u[v->id] = 1;
		ans.pb(v->id);
	}
	dfs(v->r);
}

void check(node *v) {
	if (!v) return;
	push(v);
	check(v->l);
	cerr << v->id << " " << v->key << ", ";
	check(v->r);
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	int n, q, last = 0, id = 0;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		root[i] = NULL;
	while (q--) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			id++;
			int y, k;
			scanf("%d %d", &y, &k);
			y ^= last;
			while (k--) {
				int x;
				scanf("%d", &x);
				x ^= last;
				pnn p = split(root[x], y);
				node *u = new node(y, id);
				root[x] = merge(merge(p.F, u), p.S);
			}
		}
		else {
			int x, y;
			scanf("%d %d", &x, &y);
			x ^= last;
			y ^= last;
			if (!root[x]) {
				puts("0");
				last = 0;
				continue;
			}
			root[x]->key -= y;
			root[x]->keep -= y;
			pnn p = split(root[x], 0);
			root[x] = p.S;
			ans.clear();
			dfs(p.F);
			printf("%d ", sz(ans));
			for (auto i : ans)
				printf("%d ", i);
			puts("");
		}
		cerr << "check\n";
		for (int i = 1; i <= n; i++) {
			cerr << i << " : ";
			check(root[i]);
			cerr << "\n";
		}
		cerr << "\n";
	}
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
