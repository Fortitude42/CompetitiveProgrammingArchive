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
   
   
const int N = 1e6 + 43, inf = 1e9, mod = 1e9 + 7;
const double pi = acos(-1);    
const ll INF = 1e18;
//fucking constants


int T, n, m, a[N], b[N], t[N+N][2], R;
vi vals;

void inc(int pos, int lvl, int x) {
	if (lvl)
		pos = sz(vals) - 1 - pos;
	while (pos < sz(vals)) {
		t[pos][lvl] += x;	
		pos |= pos + 1;
	}
}

int get(int r, int lvl) {
	if (lvl)
		r = sz(vals) - 1 - r;
	int res = 0;

	while (r >= 0) {
		res += t[r][lvl];
		r = (r & (r + 1)) - 1;
	}

	return res;
}


ll solve(int l, int r, int optl, int optr) {
	if (l > r)
		return 0;
		
	int m = (l + r) >> 1;
	int optm = optl;
	int res = get(b[m] + 1, 1) + get(b[m] - 1, 0);
	int cur = res;

	for (int j = optl + 1; j <= optr; ++j) {
		if (a[j] < b[m])
			--cur;
		if (a[j] > b[m])
			++cur;

		if (res > cur) {
			res = cur;
			optm = j;
		}
	}

	ll ans = res + solve(l, m - 1, optl, optm);
	
	while (R < optm) {
		inc(a[++R], 1, 1);                           
		inc(a[R], 0, -1); 
	}
	

	return ans + solve(m + 1, r, optm, optr);
}


main () {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);        
		    vals.pb(a[i]);
		}
	
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &b[j]);
			vals.pb(b[j]);
		}

		sort(all(vals));
		vals.resize(unique(all(vals)) - vals.begin());

		for (int i = 1; i <= n; ++i) 
			a[i] = lower_bound(all(vals), a[i]) - vals.begin();

		for (int i = 1; i <= m; ++i)
			b[i] = lower_bound(all(vals), b[i]) - vals.begin();

		sort(b + 1, b + 1 + m);

		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += get(a[i] + 1, 1);
			inc(a[i], 1, 1);
		}

		for (int i = 0; i < sz(vals); ++i)
			t[i][1] = 0;

		for (int i = 1; i <= n; ++i)
			inc(a[i], 0, 1);

		R = 0;
		printf("%lld\n", ans + solve(1, m, 0, n));


		for (int i = 0; i < sz(vals); ++i)
			for (int j = 0; j < 2; ++j)
				t[i][j] = 0;

		vals.clear();
	}
	
} 