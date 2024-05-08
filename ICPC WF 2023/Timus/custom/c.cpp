#include <bits/stdc++.h>
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define mp make_pair
#define ppb pop_back
using namespace std;
using ll = long long;
using pii = pair <int, int>;
using vi = vector <int>;
const int N = 100 + 5;

vector < pii > ans;
int n, k, c[N];
vector < int > g[N], tmp;
bool used[N];


void op(int x, int y) {
	ans.pb({x, y});
		
	assert(sz(g[x]) > 0 && sz(g[y]) + 1 <= c[y]);
	
	int v = g[x].back();
	g[x].ppb();
	
	g[y].pb(v);
}


bool in(int i, int j) {
	for (auto x : g[j])
		if (x == i)
			return 1;
			
	return 0;
}

pii get(int i) {
	int need = 0;
	for (int j = 1; j <= i; ++j)
		if (!used[j])
			++need;
			
	for (int j = 1; j <= k; ++j) {
		if (need <= c[j])
			return mp(j, need);			
		need -= c[j];
	}
	assert(0);
}

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= c[i]; ++j) {
			int x;
			cin >> x;
			if (x > 0)				
				g[i].pb(x);
		}
	}
	
    vector < pii > order;
    for (int i = 1; i <= n; ++i) {
        pii cur = get(i);
        order.pb(mp(c[cur.f] - cur.s, i));
    }
    
    sort(all(order));
    reverse(all(order));
	
	int cnt = k;
	for (auto o : order) {				
	    int i = o.s;
		pii tmp = get(i);		
		int j1 = tmp.f, p1 = tmp.s, j2 = -1, p2 = -1;
		assert(p1 == 1);
		
		for (int j = 1; j <= k; ++j) {
			for (int ind = 0; ind < sz(g[j]); ++ind)
				if (g[j][ind] == i) {	
					j2 = j;
					p2 = ind + 1;
				}
		}
				
				
		assert(j2 != -1);				
		if (j1 != j2) {			
			for (int j = 1; j <= k; ++j) {
				if (j == j2)
					continue;
				while (sz(g[j]) < c[j] && sz(g[j2]) != p2) 
					op(j2, j);				
			}
			
			assert(sz(g[j2]) == p2);
			if (sz(g[j1]) == c[j1]) {
				for (int j = 1; j <= k; ++j)
					if (j != j1 && j != j2 && sz(g[j]) < c[j]) {
						op(j1, j);
						break;
					}
			}
			assert(sz(g[j1]) < c[j1]);
			op(j2, j1);
			j2 = j1;
			p2 = sz(g[j2]);
		}
		
		assert(j1 == j2);		
		assert(in(i, j2));
		
		for (int j = 1; j <= k; ++j)
			while (j != j2 && sz(g[j]) < c[j] && sz(g[j2]) > p2)
				op(j2, j);
				
		assert(sz(g[j2]) == p2);
		int j3 = -1;
		
		for (int j = 1; j <= k; ++j)
			if (j != j2) {
			    if (j3 == -1 || c[j] < c[j3])
				    j3 = j;
			}
			
		assert(j3 != -1);
		
		for (int j = 1; j <= k; ++j) {
			if (j == j2 || j == j3)
				continue;
				
			while (sz(g[j3]) + 1 < c[j3] && sz(g[j]) > 0)
				op(j, j3);
		}
					
		op(j2, j3);
		
		for (int j = 1; j <= k; ++j) {
			if (j == j2 || j == j3)
				continue;
				
			while (sz(g[j2]) > 0 && sz(g[j]) < c[j])
				op(j2, j);			
		}/*
		cout << j2 << ' ' << j3 << endl;
		for (int i = 1; i <= k; ++i) {
			cout << i << ", " << c[i] << "--> ";
			for (auto j : g[i])
				cout << j << ' ';
			cout << endl;
		}
		cout << endl << endl;		*/
		return 0;
		
		assert(sz(g[j2]) == 0);
		op(j3, j2);
		g[j2].ppb();
		c[j2]--;
		used[i] = 1;
		if (!c[j2])
			cnt--;
		
		
		for (int i = 1; i <= k; ++i) {
			cout << i << ", " << c[i] << "--> ";
			for (auto j : g[i])
				cout << j << ' ';
			cout << endl;
		}
		cout << endl << endl;		
		
	}
	
	
	for (auto x : ans)
		cout << x.f << ' ' << x.s << "\n";
	cout << 0 << ' ' << 0 << "\n";
	return 0;
}
