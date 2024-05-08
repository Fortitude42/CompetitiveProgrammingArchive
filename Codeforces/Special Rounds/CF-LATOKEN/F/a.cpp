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
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
   
   
const int N = 1e6 + 43, inf = 1e9, mod = 998244353;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

bool was[N][2];
vector < pii > order, g[N][2];
int n, m, a[N], mn[N];
vector < char > c[N];

int get (int i, int j) {
	return i*m + j;
}

bool in (int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}


void dfs (int v, int i) {
	was[v][i] = 1;
	for (auto to : g[v][i])
		if (!was[to.f][to.s])
			dfs(to.f, to.s);

	order.pb(mp(v, i));
}

void dfs1 (int v, int i) {
	was[v][i] = 1;
	for (auto to : g[v][i])
		if (!was[to.f][to.s])
			dfs1(to.f, to.s);
}


main () {
	fastio
	cin >> n >> m;
	for (int j = 0; j < m; ++j)
		mn[j] = n;

	for (int i = 0; i < n; ++i) {
	    c[i].resize(m);
		for (int j = 0; j < m; ++j)
			cin >> c[i][j];
	}

	for (int i = 1; i <= m; ++i)
		cin >> a[i];


	for (int j = 0; j < m; ++j)
		for (int i = 0; i < n; ++i) {
			for (int x = 0; x < 4; ++x) {
				int toi = i + dx[x], toj = j + dy[x];
				if (!in(toi, toj))
				    continue;

				if (c[i][j] == '#') 
					g[get(i, j)][0].pb(mp(get(toi, toj), 0));
				g[get(i, j)][1].pb(mp(get(toi, toj), 0));
			}

			if (i < n - 1)  {
				if (c[i][j] == '#')
					g[get(i, j)][0].pb(mp(get(i + 1, j), 1)); 
				g[get(i, j)][1].pb(mp(get(i + 1, j), 1));
			}
		}

	for (int i = 0; i < n*m; ++i)
		for (int j = 0; j < 2; ++j)
			if (!was[i][j])
				dfs(i, j);

	reverse(all(order));
	memset(was, 0, sizeof(was));

	int ans = 0;
	for (auto i : order)
		if (i.s == 0 && !was[i.f][i.s] && c[i.f / m][i.f % m] == '#') {
			dfs1(i.f, i.s);
			++ans;
		}

	cout << ans << endl;
} 