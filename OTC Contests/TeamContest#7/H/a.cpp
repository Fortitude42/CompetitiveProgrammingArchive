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
                                                              
const int inf = 1e9, maxn = 2e5 + 48, mod = 1e9 + 7, N = 1e5 + 512;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, block = 300;
const pii base = mp(1171, 3307), Mod = mp(1e9 + 7, 1e9 + 9);
const db eps = 1e-12, pi = acos(-1);
const ll INF = 1e18;

 

int tot[10], win[10], win1[10], diff[10], goal[10], a, b, i, j, c;
vector < pair < pii, pii > > g[10];
pair < pii, int > S[10][10];
map < string, int > id;
string s, t;


int cmp (int i, int j, int x) {	
	if (win[i] != win[j])
		return (win[i] > win[j]);

	if (x == 1)
		return -1;

	if (win1[i] != win1[j])
		return (win1[i] > win1[j]);

	if (x == 2)
		return -1;

	if (diff[i] != diff[j])
		return (diff[i] > diff[j]);

	if (x == 3)	
		return -1;

	if (goal[i] != goal[j])
		return (goal[i] > goal[j]);

	return -1;
}

bool cmp1 (int i, int j) {
	return S[i][j].f.f > S[i][j].f.s;
}

                                                    
main () {
	id["Russia"] = 1;
	id["Finland"] = 2;
	id["NA"] = 3;
	id["Sweden"] = 4;
	
	s = "OT";
	for (int x = 0; x < 5; ++x) {
		if (s == "OT")
			cin >> s;
		cin >> t;
		cin >> a >> b;
		i = id[s], j = id[t];
		
		cin >> s;
		c = (s == "OT");

		g[i].pb(mp(mp(j, c), mp(a, b)));
		g[j].pb(mp(mp(i, c), mp(b, a)));

		S[i][j] = mp(mp(a, b), c);
		S[j][i] = mp(mp(b, a), c);
	}
	cerr << endl;

	if (s == "OT")
		cin >> s;
	cin >> t;
	int i, j, L = 0, W = 0;
	i = id[s], j = id[t];


	for (int x = 0; x <= 50; ++x) {		
		for (int y = 0; y <= 50; ++y) {
			for (int cc = -1; cc <= 1; ++cc) {
				if (x == y)
					continue;
				if (cc == 1 && x + 1 != y)
					continue;

				if (cc == -1 && x != y + 1)	
					continue;

				S[i][j] = mp(mp(x, y), abs(cc));
				S[j][i] = mp(mp(y, x), abs(cc));

				g[i].pb(mp(mp(j, abs(cc)), mp(x, y)));
				g[j].pb(mp(mp(i, abs(cc)), mp(y, x)));

					
				for (int i = 1; i <= 4; ++i) {
					tot[i] = win[i] = diff[i] = goal[i] = win1[i] = 0;

					for (auto z : g[i]) {
						int a = z.s.f, b = z.s.s, j = z.f.f, c = z.f.s;

						goal[i] += a;
						diff[i] += a - b;

						if (a > b) {
							tot[i] += 2;
							win[i]++;
							if (!c)
								win1[i]++;
						} else if (c)
							tot[i]++;
					}
				}

				g[i].ppb();
				g[j].ppb();


				int cntw = 0, cntl = 0;
				for (int i = 2; i <= 4; ++i)
					if (tot[i] > tot[1])
						++cntl;
					else if (tot[i] < tot[1])
						++cntw;
				
				        	
				if (cntw > 1)	
					++W;
				else if (cntl > 1)
					++L;
				else {
					set < int > q, qq;

					for (int i = 2; i <= 4; ++i)
						if (tot[i] == tot[1])
							q.insert(i);


					bool found = 0;
					for (int x = 1; x <= 4; ++x) {
						qq.clear();

						if (sz(q) == 1) {
							int x = *q.begin();
							if (cmp1(1, x))
								++W;
							else
								++L;
							found = 1;
							break;
						}

						for (auto y : q)
							if (cmp(1, y, x) > 0)
								++cntw;
							else if (cmp(1, y, x) == 0)
								++cntl;
							else
								qq.insert(y);

					 	if (cntl > 1) {
					 		L++;
					 		found = 1;
							break;
					 	}

					 	if (cntw > 1) {
					 		W++;
					 		found = 1;
					 		break;
					 	}

						q = qq;
						
						if (sz(q) == 1) {
							int x = *q.begin();
							if (cmp1(1, x))
								++W;
							else
								++L;
							found = 1;
							break;
						}
					}



					if (!found) {
						++W, ++L;
					}
				}
			}
		}
	}

	if (!W)
		puts("No chance");
	else if (!L)
		puts("Already in playoff!");
	else
		puts("Believe in playoff!");
}