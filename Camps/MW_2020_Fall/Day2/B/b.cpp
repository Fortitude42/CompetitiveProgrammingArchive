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

#define f first
#define s second

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

const int N = 100500;

int n, c[N], dp[N], timer, t[N], OK;

bool check1 (int x) {
	++timer;
	deque < int > st;
	vector < pii > v, vv;

	for (int i = 0; i < n; ++i) {
		if (c[i] == 2)
			st.pb(i);

		if (c[i] == 0 && sz(st)) {
			int j = st.front();
			st.pop_front();
			v.pb(mp(j, i));
			t[i] = t[j] = timer;
			if (sz(v) == x)
				break;
		}
	}

	if (sz(v) < x)
		return 0;

	while (sz(st))
		st.pop_back();

	for (int i = n - 1; i >= 0; --i) {
		if (t[i] == timer)
			continue;

		if (c[i] == 0)
			st.pb(i);

		if (c[i] == 2 && sz(st)) {
			int j = st.front();
			st.pop_front();
			vv.pb(mp(i, j));
			if (sz(vv) == x)
				break;				
		}
	}

	if (sz(vv) < x)
		return 0;

	reverse(all(vv));

	if (OK) {
	for (int i = 0; i < x; ++i)
		cerr << v[i].f << ' ' << v[i].s << endl;
	cerr << endl << endl;

	for (int i = 0; i < x; ++i)
		cerr << vv[i].f << ' ' << vv[i].s << endl;
	}
	for (int i = 0; i < x; ++i)
		if (v[i].s >= vv[i].f)
			return 0;

	return 1;        	
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
 	n = 15;

	for (int msk = 0; msk < (1 << 15); msk++) {
		for (int j = 0; j < 15; j++)
			c[j] = ((msk >> j & 1) ? 0 : 2);
		int check = 0;
		for (int mask = 0; mask < (1 << 15); mask++) {
			dp[mask] = 0;
			for (int i = 0; i < 15; i++) {
				if (c[i] != 2 || !(mask >> i & 1)) continue;
				for (int j = i + 1; j < 15; j++) {
					if (c[j] != 0 || !(mask >> j & 1)) continue;
					for (int k = j + 1; k < 15; k++) {
						if (c[k] != 2 || !(mask >> k & 1)) continue;
						for (int l = k + 1; l < 15; l++) {
							if (c[l] != 0 || !(mask >> l & 1)) continue;
							dp[mask] = max(dp[mask], dp[mask ^ (1 << i) ^ (1 << j) ^ (1 << k) ^ (1 << l)] + 1);
						}
					}
				}
			}
			check = max(check, dp[mask]);
		}
		
		int l = 1, r = n / 4, res = 0;

		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check1(mid)) {
				res = mid;
				l = mid + 1;
			} else
				r = mid - 1;							
		}

		if (check != res) {
			OK = 1;
			check1(res + 1);
			cout << n << endl;
			for (int i = 0; i < n; ++i)
				cout << c[i];
			cerr << endl;
			cerr << check << ' ' << res << endl;
			return 0;				
		}

		cout << msk << ' ';
		
	}
	
	/*int n;
	while (cin >> n) {
		string s;
		cin >> s;
		set < int > zer, two;
		for (int i = 0; i < n; i++) {
			if (s[i] == '0')
				zer.insert(i);
			if (s[i] == '2')
				two.insert(i);
		}
		int ans = 0;
		while (min(sz(zer), sz(two)) >= 2) {
			int pos = *two.bg;

			set < int > :: iterator it1 = zer.upper_bound(pos);
			if (it1 == zer.en) break;
			int pos1 = *it1;

			set < int > :: iterator it2 = two.upper_bound(pos1);
			if (it2 == two.en) break;
			int pos2 = *it2;

			set < int > :: iterator it3 = zer.upper_bound(pos2);
			if (it3 == zer.en) break;
			int pos3 = *it3;

			ans++;
			two.erase(pos);
			two.erase(pos2);
			zer.erase(pos1);
			zer.erase(pos3);
		}
		cout << ans << "\n";
	}*/
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}