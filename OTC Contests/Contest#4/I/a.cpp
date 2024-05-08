#include <bits/stdc++.h>                                           
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
#define s second
#define f first
 
 
 
 
typedef pair < long long, long long > pll;    
typedef pair < int, int > pii;  
typedef unsigned long long ull;         
typedef vector < pii > vpii;                                   	
typedef vector < int > vi;
typedef long double ldb;  
typedef long long ll;  
typedef double db;
 
typedef tree < int, null_type, less < int >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
 
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 3e5 + 12;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;


struct node {
	int val, prior, add;
	node *l, *r;
	node () {
	
	}
	
	node (int v, int p) {
		l = r = NULL;
		val = v;
		prior = p;
		add = 0;
	}
};

typedef node * pnode;

void push (pnode &t) {
	if (!t || !t->add)
		return;
	
	if (t->l) {
		t->l->add += t->add;
		t->l->val += t->add;
	}

	if (t->r) {
		t->r->add += t->add;
		t->r->val += t->add;
	}
	t->add = 0;
}

void split (pnode t, int key, pnode &l, pnode &r) {
    if (!t) {
    	l = r = NULL;
    	return;
    }

    push(t);
    if (key < t->val) {
    	split(t->l, key, l, t->l);
    	r = t;
    } else {
    	split(t->r, key, t->r, r);
    	l = t;
    }
}	

void merge (pnode &t, pnode l, pnode r) {
	push(l);
	push(r);

	if (!l)
		t = r;
	else if (!r)
		t = l;
	else if (l->prior > r->prior) {
		merge(l->r, l->r, r);
		t = l;
	} else {
		merge(r->l, l, r->l);
		t = r;
	}

	push(t);
}

pnode DelLeft (pnode t) {
	if (!t)
		return NULL;
	if (!t->l)
		return t->r;

	t->l = DelLeft(t->l);
	return t;
}

pnode root = NULL, a, b, c;
int n, l, r;

int getRand () {
	int res = 0;

	for (int i = 30; i >= 0; --i)
		if (rand() & 1)
			res += (1 << i);

	return res;
}

int getCnt (pnode t) {
	if (!t)
		return 0;

	return 1 + getCnt(t->l) + getCnt(t->r);
}

void out (pnode t) {
	if (!t)
		return;

	push(t);
	out(t->l);
	cerr << t->val << ' ';
	out(t->r);
}

 
main () {
	scanf("%d", &n);

	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l, &r);
		split(root, l - 1, root, a);


		split(a, r - 1, b, c);
//		out(b);
//		cerr << endl;
		c = DelLeft(c);
//		out(c);
//		cerr << endl;
		if (b) {
			b->val++;
			b->add++;
		}

		a = new node(l, getRand());
		merge(root, root, a);
		merge(root, root, b);
		merge(root, root, c);
//		out(root);
//		cerr << endl << endl;
	}

	cout << getCnt(root) << endl;
}