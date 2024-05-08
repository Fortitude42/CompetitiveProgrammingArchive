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
const int N = 50, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


int n;
int a[M][2002];
string s[M];

int binpow(int a, ll n, int m) {
	int res = 1;
	while (n > 0) {
		if (n & 1)
			res = res * 1ll * a % m;
		n >>= 1;
		a = a * 1ll * a % m;
	}

	return res;
}

pii binpow(pii a, ll n) {
	return mp(binpow(a.f, n, mod.f), binpow(a.s, n, mod.s));
}


struct Hash{
	ll len;
	pii h;

	Hash() {
		len = 0;
		h = mp(0, 0);
	}

	Hash(char c) {
		len = 1;
		h = mp(c, c);
	}

	Hash(ll len, pii h): len(len), h(h) {}


	bool operator == (Hash hs) const {
		return len == hs.len && h == hs.h;
	}
	
	Hash append(Hash hs) {
		pii pw = binpow(base, hs.len);
		int a = (h.f * 1ll * pw.f + hs.h.f) % mod.f;
		int b = (h.s * 1ll * pw.s + hs.h.s) % mod.s;


		return Hash(len + hs.len, mp(a, b));
	}

	Hash rep(ll iter) {
		pii q = binpow(base, len);
		pii up = binpow(q, iter);
		up = mp(up.f - 1, up.s - 1);

		pii dw = mp(q.f - 1, q.s - 1);
		dw = mp(binpow(dw.f, mod.f - 2, mod.f), binpow(dw.s, mod.s - 2, mod.s));


		pii res = mp(dw.f * 1ll * up.f % mod.f * h.f % mod.f, dw.s * 1ll * up.s % mod.s * h.s % mod.s);
		return Hash(len*iter, res);
	}
};



struct Node {
	int i, l, r;
	char fst;
	Hash hs;
};

int roots[M], sz, p[M], nxt[M][2002], nxt1[M][2002];
Node nd[M*2000];
vector < pair < int, ll > > g[M*2000];
vector < Hash > gg[M*2000];


void build(int i, int l, int r, int id) {
	nd[id].i = i, nd[id].l = l, nd[id].r = r;

	nd[id].hs = Hash();
	nd[id].fst = s[i][nxt1[i][l]];

	if (nxt[i][l] > r) {//only consists for letters
		for (int j = l; j <= r; ++j)
			nd[id].hs = nd[id].hs.append(Hash(s[i][j]));

		return;
	}

	while (l <= r) {
		if (isalpha(s[i][l])) {
			int ids = ++sz;
			build(i, l, nxt[i][l] - 1, ids);
			l = nxt[i][l];

			nd[id].hs = nd[id].hs.append(nd[ids].hs);
			g[id].pb(mp(ids, 1));
			gg[id].pb(nd[id].hs);			
			continue;
		}

		assert(isdigit(s[i][l]));
		ll iter = 0;
		while (isdigit(s[i][l])) {
			iter = iter*10 + s[i][l] - '0';
			++l;
		}

		if (s[i][l] == '(') {
			int ids = ++sz;
			build(i, l + 1, a[i][l] - 1, ids);
			l = a[i][l] + 1;

			nd[id].hs = nd[id].hs.append(nd[ids].hs.rep(iter));
			g[id].pb(mp(ids, iter));
			gg[id].pb(nd[id].hs);
			continue;
		}

		assert(isalpha(s[i][l]));
		int ids = ++sz;
		build(i, l, l, ids);
		l++;

		nd[id].hs = nd[id].hs.append(nd[ids].hs.rep(iter));
		g[id].pb(mp(ids, iter));
		gg[id].pb(nd[id].hs);
	}

}

char c;


Hash get(int id, ll len) {
	if (!len) {
		c = nd[id].fst;
		return Hash();
	}

	int i = nd[id].i, l = nd[id].l, r = nd[id].r;

	if (nxt[i][l] > r) {
//		cerr << id << "hello\n";
		c = s[i][l + len];
		Hash hs = Hash();

		for (int j = l; j < l + len; ++j) {
			hs = hs.append(Hash(s[i][j]));
		}

		return hs;
	}
	
	for (int j = 0; j < sz(g[id]); ++j)
		if (gg[id][j].len > len) {
			Hash prv = !j ? Hash() : gg[id][j - 1];
			ll cur = len - prv.len;

			int ids = g[id][j].f;
			ll iter = cur / nd[ids].hs.len + 1;




			if (iter > 1) {
				prv = prv.append(nd[ids].hs.rep(iter - 1));
				cur -= (iter - 1)*nd[ids].hs.len;
			}

			prv = prv.append(get(ids, cur));
			return prv;
		}

	cerr << "---> fail";
	exit(0);
	assert(0);
	return Hash();
}


bool cmp(int i, int j) {
	ll leni = nd[roots[i]].hs.len;
	ll lenj = nd[roots[j]].hs.len;
	
	ll l = 1, r = min(leni, lenj) - 1;
	char ci = nd[roots[i]].fst, cj = nd[roots[j]].fst;

	while (l <= r) {
		ll mid = (l + r) / 2;
		char cci, ccj;
		Hash hi = get(roots[i], mid);
		cci = c;
		Hash hj = get(roots[j], mid);
		ccj = c;

	
		if (hi == hj) {
			ci = cci, cj = ccj;
			l = mid + 1;
		} else
			r = mid - 1;
	}

	if (ci != cj)
		return ci < cj;

	if (leni != lenj)
		return leni < lenj;

	return i < j;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
		stack < int > st;
		for (int j = 0; j < sz(s[i]); ++j)
			if (s[i][j] == '(')
				st.push(j);
			else if (s[i][j] == ')') {
				a[i][st.top()] = j;
				st.pop();
			}

		nxt[i][sz(s[i])] = sz(s[i]);
		nxt1[i][sz(s[i])] = sz(s[i]);
		for (int j = sz(s[i]) - 1; j >= 0; --j) {
			nxt[i][j] = nxt[i][j + 1];		
			nxt1[i][j] = nxt1[i][j + 1];		
			if (!isalpha(s[i][j]))
				nxt[i][j] = j;
			else
				nxt1[i][j] = j;
		}

		roots[i] = ++sz;
		build(i, 0, sz(s[i]) - 1, roots[i]);
//		cerr << nd[roots[i]].hs.len << endl;
	}


	for (int i = 1; i <= n; ++i)
		p[i] = i;

	sort(p + 1, p + 1 + n, cmp);
	for (int i = 1; i <= n; ++i)
		cout << p[i] << '\n';
}


main () {
	fastio
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}