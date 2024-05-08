//template by paradox & gege & parasat
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <vector>
#include <bitset>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <ctime>
#include <map>      
#include <set>      

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
#define ll long long
 
 
using namespace std;
 
 
 
 
const int N = 1e6 + 11;
 
int c_mx[N << 2], a[N], tp, l, r, x, T, n, m;
int mx1[N << 2], mx2[N << 2];
ll t[N << 2];

void f (int v) {
	t[v] = t[v << 1] + t[v << 1 | 1];
	if (mx1[v << 1] == mx1[v << 1 | 1]) {
		mx1[v] = mx1[v << 1];
		c_mx[v] = c_mx[v << 1] + c_mx[v << 1 | 1];
		mx2[v] = max(mx2[v << 1], mx2[v << 1 | 1]);
	} else if (mx1[v << 1] > mx1[v << 1 | 1]) {
		mx1[v] = mx1[v << 1];
		c_mx[v] = c_mx[v << 1];
		mx2[v] = max(mx2[v << 1], mx1[v << 1 | 1]);
	} else {
		mx1[v] = mx1[v << 1 | 1];
		c_mx[v] = c_mx[v << 1 | 1];
		mx2[v] = max(mx1[v << 1], mx2[v << 1 | 1]);
	}

}

void build (int v = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		t[v] = a[tl];
		mx1[v] = a[tl];
		mx2[v] = -1;
		c_mx[v] = 1;
		return;
	}

	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	f(v);
}

void push (int v) {
	if (mx1[v << 1] > mx1[v]) {
		t[v << 1] -= c_mx[v << 1] * 1ll *(mx1[v << 1] - mx1[v]);
		mx1[v << 1] = mx1[v];
	}	

	if (mx1[v << 1 | 1] > mx1[v]) {
		t[v << 1 | 1] -= c_mx[v << 1 | 1] * 1ll *(mx1[v << 1 | 1] - mx1[v]);
		mx1[v << 1 | 1] = mx1[v]; 		
	}
}

void update (int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r || mx1[v] <= x)
		return;
	if (l <= tl && tr <= r && mx2[v] < x) {
		t[v] -= (mx1[v] - x) * 1ll * c_mx[v];
		mx1[v] = x;
		return;
	}

	push(v);
	int tm = (tl + tr) >> 1;
	update(l, r, x, v << 1, tl, tm);						
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	f(v);
}

int get_max (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return -1;
	if (l <= tl && tr <= r)
		return mx1[v];

	push(v);			
	int tm = (tl + tr) >> 1;
	return max(get_max(l, r, v << 1, tl, tm), get_max(l, r, v << 1 | 1, tm + 1, tr));
}

ll get_sum (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return 0;
	if (l <= tl && tr <= r)
		return t[v];

	push(v);			
	int tm = (tl + tr) >> 1;
	return get_sum(l, r, v << 1, tl, tm) + get_sum(l, r, v << 1 | 1, tm + 1, tr);
}
 

int main () {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		forn (i, 1, n)
			scanf("%d", &a[i]);
		build();
		while (m--) {
			scanf("%d%d%d", &tp, &l, &r);		
			if (!tp) {
				scanf("%d", &x);
				update(l, r, x);
			} else if (tp == 1) 
				printf("%d\n", get_max(l, r));
			else
				printf("%lld\n", get_sum(l, r));
		}
	}
    return 0;  
}
