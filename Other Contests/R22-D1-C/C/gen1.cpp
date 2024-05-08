#include "testlib.h"
#include <bits/stdc++.h>                                           
 
using namespace std;
 
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

const int N = 2e5;
const int M = N + 11;


struct query{
	int tp, a, b, x;
	query() {}

	query(int Tp, int A, int B, int X) {
		tp = Tp;
		a = A;
		b = B;
		x = X;
	}

	bool operator < (const query &X) const {
		return (tp != 2 && X.tp == 2);
	}
} b[M];



int n, q, sh, sw, mixed, w, Long;

int main (int argc, char* argv[]) {
	registerGen(argc, argv, 1);
//	scanf("%d%d%d%d%d%d%d", &n, &q, &sh, &sw, &mixed, &w, &Long);
	n = opt<int>(1);
	q = opt<int>(2);
	sh = opt<int>(3);
	sw = opt<int>(4);
	mixed = opt<int>(5);
	Long = opt<int>(6);
	w = opt<int>(7);


	vector<int> p = rnd.perm(n, 1);

	if (!sh) {
		for (int i = 0; i < n; ++i) 
			p[i] = i + 1;
	}

	auto gen_seg = [&](int n, int w) -> pair<int, int> {
		int len = rnd.wnext(Long ? max(n - 1000, n / 2) : 1, n, w);
		int l = rnd.next(1, n - len + 1);
		int r = l + len - 1;
		return make_pair(l, r);
	};

	
	for (int i = 1; i <= q; ++i) {
		if (!sw) 
			b[i].tp = rnd.next(1, 2);
		else
			b[i].tp = rnd.next(1, 3);

		if (b[i].tp == 3)
			sw--;

		if (b[i].tp == 1 || b[i].tp == 2)  {
			tie(b[i].a, b[i].b) = gen_seg(n, w);
		} else {
			do {
				b[i].a = rnd.next(1, n);
				b[i].b = rnd.next(1, n);
			} while (b[i].a == b[i].b);
		}
		
		if (b[i].tp == 1)
			b[i].x = rnd.next(1, N / 2);
	}

	if (!mixed)
		sort(b + 1, b + 1 + q);

	cout << n << ' ' << q << '\n';

	for (int i = 0; i < n; ++i)
		cout << p[i] << " \n"[i == n - 1];

	for (int i = 1; i <= q; ++i) {
		cout << b[i].tp << ' ' << b[i].a << ' ' << b[i].b;
		if (b[i].tp == 1)
			cout << ' ' << b[i].x;
		cout << '\n';
	}
	
	return 0;
}