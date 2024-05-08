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
const int N = 2e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;



struct node {
	ll sum;
	int cnt, key, prior, lz, val;
	node * l, * r;
	node() {
		l = NULL;
		r = NULL;
	}

	node(int k, int pr) {
		key = k;
		prior = pr;
		cnt = 1;
		sum = 0;
		lz = 0;
		val = 0;
		l = r = NULL;
	}
};

typedef node * pnode;

int cnt(pnode t) {
	return t ? t->cnt : 0;
}

ll sum(pnode t) {
	return t ? t->sum : 0;
}

void upd_cnt(pnode t) {
	if (t) {
		t->cnt = 1 + cnt(t->l) + cnt(t->r); 
		t->sum = t->val + sum(t->l) + sum(t->r);
	}
}

void push(pnode t) {
	if (t && t->lz != 0) {
		if (t->l) {
			t->l->lz += t->lz; 
			t->l->val += t->lz;
			t->l->sum += t->lz * 1ll * t->l->cnt;
		}
		if (t->r) {
			t->r->lz += t->lz;
			t->r->val += t->lz;
			t->r->sum += t->lz * 1ll * t->r->cnt;
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
	upd_cnt(t);
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

	upd_cnt(l);
	upd_cnt(r);
}


pnode T, A, B, C, D, E;
bool was[M];
int q, d, timer;
ll ans;

int getRand() {
//	return timer++;
	int res = 0;
	for (int i = 0; i < 30; ++i)
		if (rand() & 1)
			res |= (1 << i);

	return res;
}

void write(pnode t) {
	if (!t)
		return;

	write(t->l);
	cerr << t->key << ' ';
	write(t->r);
}

void solve() {
	cin >> q >> d;
	while (q--) {
		int x;                       
		cin >> x;
		if (!was[x]) {
			split(T, x - d, A, B);
			split(B, x, B, C);
			split(C, x + d + 1, C, D);
			E = new node(x, getRand());

//			cerr << "A: ";write(A);cerr << "-->  " << (!A ? 0 : A->sum) << endl;
//			cerr << "B: ";write(B);cerr << "-->  " << (!B ? 0 : B->sum) << endl;
//			cerr << "C: ";write(C);cerr << "-->  " << (!C ? 0 : C->sum) << endl;
//			cerr << "D: ";write(D);cerr << "--> " << (!D ? 0 : D->sum) << endl;
//			cerr << "E: ";write(E);cerr << "-->  " << (!E ? 0 : E->sum) << endl << endl;

			int cntb = cnt(B);
			ans += cntb * 1ll * (cntb - 1) / 2;
			if (C) {
				ans += C->sum;
				C->sum += C->cnt;
				C->val++;
				C->lz++;
			}

			E->sum = E->val = cntb;

			merge(B, A, B);
			merge(B, B, E);
			merge(C, B, C);
			merge(T, C, D);
		} else {
			split(T, x - d, A, B);
			split(B, x, B, C);
			split(C, x + 1, E, C);
			split(C, x + d + 1, C, D);

			int cntb = cnt(B);
			ans -= cntb * 1ll * (cntb - 1) / 2;

			if (C) {
				C->sum -= C->cnt;
				C->val--;
				C->lz--;
				ans -= C->sum;
			}

			merge(B, A, B);
			merge(C, B, C);
			merge(T, C, D);
		}
		was[x] ^= 1;

		cout << ans << endl;
	}
}

main () {
	srand(time(0));
	int TT = 1;
//  scanf("%d", &TT);
  	for (int tt = 1; tt <= TT; ++tt) {
    	solve();
  	}
}