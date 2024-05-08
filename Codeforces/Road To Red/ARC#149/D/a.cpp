//template by paradox & gege & parasat
#include <bits/stdc++.h>                                           
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
 
//#define int long long
//#pragma GCC optimize("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
 
 
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(s) (int)s.size()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define se second
#define fi first
#define s second
#define f first
 
 
typedef pair < int, int > pii;  
typedef vector < int > vi;
typedef long double ld;  
typedef long long ll;  
 
//typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 

const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1e6 + 3, 1e6 + 7), mod = mp(1e9 + 7, 1e9 + 9);
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

struct node {
	int key, ind, prior, lz, mx;
	node *l, *r;
	node() {
		l = NULL;
		r = NULL;
	}

	node(int k, int i, int p) {
		l = NULL;
		r = NULL;
		mx = key = k;
		prior = p;
		lz = 0;
		ind = i;
	}

};

int getRand() {
//	return timer++;
	int res = 0;
	for (int i = 0; i < 30; ++i)
		if (rand() & 1)
			res |= (1 << i);
 
	return res;
}


typedef node * pnode;

int getmx(pnode t) {
	return !t ? 0 : t->mx;
}

void upd_mx(pnode t) {
	if (t) {
		t->mx = max({t->key, getmx(t->l), getmx(t->r)}); 
	}
}
 
void push(pnode t) {
	if (t && t->lz != 0) {
		if (t->l) {
			t->l->lz += t->lz; 
			t->l->key += t->lz;
			t->l->mx += t->lz;
		}
		if (t->r) {
			t->r->lz += t->lz;
			t->r->key += t->lz;
			t->r->mx += t->lz;
		}
		t->lz = 0;
	}
}


void merge(pnode &t, pnode l, pnode r) {
	push(l);
	push(r);
 
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior) {
		merge(l->r, l->r, r); 
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}
	upd_mx(t);
}
 
void split(pnode t, int key, pnode &l, pnode &r) {
	if (!t) {
		l = r = NULL;
		return;
	}
	push(t);
 
	if (t->key < key) {
		split(t->r, key, t->r, r);
		l = t;
	} else {
		split(t->l, key, l, t->l);
		r = t;
	}
 
	upd_mx(l);
	upd_mx(r);
}

void write(pnode t) {
	if (!t)
		return;
 
	write(t->l);
	cerr << t->key << ' ';
	write(t->r);
}


bool bad[M];
int n, m, res[M];
pnode T, A, B, C, D, E, F;

void del(pnode t, int x) {
	if (!t)
		return;
	if (x == -1)
		res[t->ind] = t->key;
	else {
		res[t->ind] = x; 
		bad[t->ind] = 1;
	}

}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		A = new node(x, i, getRand());
		merge(T, T, A);
	}

	for (int i = 1; i <= m; ++i) {
		int d;
		cin >> d;
		split(T, -d - 1, A, T);
		split(T, -d, B, T);
		split(T, 0, C, T);
		split(T, d - 1, D, T);
		split(T, d, E, F);

		del(B, i);
		del(E, i);

		if (A) {
			A->key += d;
			A->lz += d;
			A->mx += d;
		}

		if (C) {
			C->key += d;
			C->lz += d;
			C->mx += d;
		}

		if (D) {
			D->key -= d;
			D->lz -= d;
			D->mx -= d;
		}

		if (F) {
			F->key -= d;
			F->lz -= d;
			F->mx -= d;
		}
	}
}

main () {
	fastio
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}