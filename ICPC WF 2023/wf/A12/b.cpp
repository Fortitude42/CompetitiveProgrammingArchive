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
const double eps = 5e-7;
const double EPS = 1e-12;
const int maxn = 1e5;

bool used[maxn];
int n, p[maxn], order[maxn];
double x[maxn], y[maxn], z[maxn];
double vx[maxn], vy[maxn], vz[maxn], d[maxn];

double dist(int i, int j, double t) {
	return (x[i] + vx[i]*t - x[j] - vx[j]*t)*(x[i] + vx[i]*t - x[j] - vx[j]*t) +
		   (y[i] + vy[i]*t - y[j] - vy[j]*t)*(y[i] + vy[i]*t - y[j] - vy[j]*t) + 
		   (z[i] + vz[i]*t - z[j] - vz[j]*t)*(z[i] + vz[i]*t - z[j] - vz[j]*t);
}

void build() {
	for (int i = 1; i <= n; ++i)
		p[i] = i;
}

int get(int v) {
	return v == p[v] ? v : p[v] = get(p[v]);
}

void merge(int v, int u) {
	v = get(v), u = get(u);
	if (v == u)
		return;

	if (rand() & 1)
		swap(v, u);

	p[u] = v;
}


bool cmp(int i, int j) {
	return d[i] < d[j];
}
 
void solve(int tt) {
	for (int i = 1; i <= n; ++i)
		cin >> x[i] >> y[i] >> z[i] >> vx[i] >> vy[i] >> vz[i];
	
	vector < pii > edges;
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			edges.pb({i, j});	
	if (sz(edges) >= maxn)
		exit(0);

	vector < pair < double, pii > > v;
	for (int i = 0; i < sz(edges); ++i)
		for (int j = i + 1; j < sz(edges); ++j) {
			int a = edges[i].f, b = edges[i].s;
			int c = edges[j].f, d = edges[j].s;

			double A = (vx[a] - vx[b]) * (vx[a] - vx[b]) - (vx[c] - vx[d]) * (vx[c] - vx[d]) +
			           (vy[a] - vy[b]) * (vy[a] - vy[b]) - (vy[c] - vy[d]) * (vy[c] - vy[d]) +
			           (vz[a] - vz[b]) * (vz[a] - vz[b]) - (vz[c] - vz[d]) * (vz[c] - vz[d]);
			
			double B = 2*(x[a] - x[b]) * (vx[a] - vx[b]) - 2*(x[c] - x[d]) * (vx[c] - vx[d]) +
			           2*(y[a] - y[b]) * (vy[a] - vy[b]) - 2*(y[c] - y[d]) * (vy[c] - vy[d]) +
			           2*(z[a] - z[b]) * (vz[a] - vz[b]) - 2*(z[c] - z[d]) * (vz[c] - vz[d]);
			
			double C = (x[a] - x[b]) * (x[a] - x[b]) - (x[c] - x[d]) * (x[c] - x[d]) +
			           (y[a] - y[b]) * (y[a] - y[b]) - (y[c] - y[d]) * (y[c] - y[d]) +
			           (z[a] - z[b]) * (z[a] - z[b]) - (z[c] - z[d]) * (z[c] - z[d]);

			if (!A) {
				if (B != 0)
					v.pb(mp((-C + 0.0) / B, mp(i, j)));
				continue;
			}

			
			double D = B*B - 4*A*C;
			if (D < 0)
				continue;

			D = sqrtl(D);
			v.pb(mp((D - B + 0.0) / (2*A), mp(i, j)));
			v.pb(mp((-D - B + 0.0) / (2*A), mp(i, j)));
		}



	sort(all(v));

	int ans = 1;
	bool fst = 1;
	set < int > u;

	for (int i = 0; i < sz(v); ) {
		if (v[i].f <= 0) {
		    ++i;
			continue;		
		}

		if (fst) {
			fst = 0;
			for (int e = 0; e < sz(edges); ++e) {
				d[e] = dist(edges[e].f, edges[e].s, v[i].f - eps);
				order[e] = e;
			}

			sort(order, order + sz(edges), cmp);
			build();
			for (int e = 0; e < sz(edges); ++e) {
				int j = order[e];
				if (get(edges[j].f) != get(edges[j].s)) {
					merge(edges[j].f, edges[j].s);
					used[j] = 1;
					u.insert(j);
				} else
					used[j] = 0;
			}
		}
            
		int j = i;
		vi es;
		while (j < sz(v) && fabs(v[i].f - v[j].f) <= eps) {
			es.pb(v[j].s.f);
			es.pb(v[j].s.s);
			++j;
		}

//		cerr << sz(es) << "--> " << es[0] << ' ' << es[1] << endl;
//		for (int tmp = 0; tmp < sz(edges); ++tmp)
//			es.pb(tmp);

		sort(all(es));
		es.resize(unique(all(es)) - es.begin());


		for (auto e : es) {
			if (u.count(e))
				u.erase(e);
			d[e] = dist(edges[e].f, edges[e].s, v[i].f + eps);
		}

		build();
		for (auto e : u)
			merge(edges[e].f, edges[e].s);

		sort(all(es), cmp);
		bool diff = 0;
		for (auto e : es) {
			if (get(edges[e].f) != get(edges[e].s)) {
				u.insert(e);
				merge(edges[e].f, edges[e].s);
				if (!used[e]) {
					used[e] = 1;
					diff = 1;					
				}
			} else {
				if (used[e]) {
					diff = 1;
					used[e] = 0;
				}					
			}
		
		}

		ans += diff;		
		i = j;
	}




	cout << "Case " << tt << ": " << ans << "\n";
}

main () {
	int tt = 0;
	while (cin >> n) {
		solve(++tt);
	}
}