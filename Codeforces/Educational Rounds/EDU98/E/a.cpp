/*
Confine me let me be the lesser of a beautiful man
Without the blood on his hands
Come and make me a martyr come and break my feeling
With your violence with the gun on my head
 
Ready to take
Ready to take
Ready to take
Ready to take out anyone, anywhere
Anyone, anywhere
Anyone, anywhere
Anyone, anywhere
Anyone, anywhere
 
Black holes living in the side of your face
Razor wire spinning around your
Around your
Around your
Around your (blistering sky)
Around your (blistering sky)
Around your (blistering sky)
 
Bullets are the beauty of the blistering sky
Bullets are the beauty and I don’t know why
Bullets are the beauty of the blistering sky
Bullets are the beauty and I don’t know why
 
Personal responsibility
Personal responsibility
Personal responsibility (Insanity)
Personal responsibility (Insanity)
*/
#include <bits/stdc++.h>                                           
 
 
//#define int long long	
#define file(s) freopen(s".in","r",stdin); freopen(s".out","w",stdout);
#define ll long long
#define vi vector < int >
#define pii pair < int, int > 
#define sz(s) (int)s.size()
#define all(x) x.begin(), x.end()                                                                    
#define pb push_back   
#define ppb pop_back
#define mp make_pair
#define s second
#define f first                                               
	
   
using namespace std;                  
   
   
const int N = 2e3 + 43, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants


int n, m, k, l[N], r[N], ans, L1, R1, L2, R2, t[N << 2], add[N << 2];
vi g[N];

inline int inter (int la, int ra, int lb, int rb) {
	return max(0, min(ra, rb) - max(la, lb) + 1); 
}

inline void push (int v, int tl, int tr, int tm) {
	if (add[v]) {
		t[v << 1] += add[v] * (tm - tl + 1);
		t[v << 1 | 1] += add[v] * (tr - tm);
		
		add[v << 1] += add[v];
		add[v << 1 | 1] += add[v];

		add[v] = 0;
	}
}

void update (int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || l > tr || tl > r)
		return;

	if (l <= tl && tr <= r) {
		t[v] += (tr - tl + 1) * x;
		add[v] += x;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = t[v << 1] + t[v << 1 | 1];
}

int get (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	return get(l, r, v << 1, tl, tm) + get(l, r, v << 1 | 1, tm + 1, tr);
}


main () {
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i)
		cin >> l[i] >> r[i];
	
	for (L1 = 1, R1 = L1 + k - 1; R1 <= n; ++L1, ++R1) {
		for (int i = 0; i < (N << 2); ++i)
			t[i] = add[i] = 0;
		for (int i = 1; i <= n; ++i)
			g[i].clear();

		int cur = 0;
		for (int i = 1; i <= m; ++i) {
			update(l[i], r[i], 1);
			if (!inter(l[i], r[i], L1, R1)) 
				continue;			
				
				
			int lf = L1, rg = n - k + 1, j = L1 - 1;
			while (lf <= rg) {
				int mid = (lf + rg) / 2;
				if (inter(l[i], r[i], L1, R1) > inter(l[i], r[i], mid, mid + k - 1)) {
					j = mid;
					rg = mid - 1;
				} else
					lf = mid + 1;
			}

			g[j].pb(i);
//			cerr << i << ' ' << j << endl;
//			cur += inter(l[i], r[i], L1, R1);
		}

		for (L2 = L1, R2 = L2 + k - 1; R2 <= n; ++L2, ++R2) {
			for (auto i : g[L2]) {
				cur += inter(L1, R1, l[i], r[i]);
				update(l[i], r[i], -1);
			}

			ans = max(ans, cur + get(L2, R2));
		}

//		cerr << ans << endl;
//		return 0;

	}
	
	cout << ans << endl;
}           