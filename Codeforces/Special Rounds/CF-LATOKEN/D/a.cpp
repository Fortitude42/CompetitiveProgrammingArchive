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
   
   
const int N = 2043, inf = 1e9, mod = 998244353;
const double pi = acos(-1);
const ll INF = 1e18;
//fucking constants

int n, d[N][N], e[N];
vector < pii > ans;

void ask (int root) {
	if (d[root][root] != -1)
		return;

	cout << "? "  << root << endl;
	for (int i = 1; i <= n; ++i)
		cin >> d[root][i];		
}

void solve (int root, vi v) {
	if (!sz(v))
		return;

//	ask(root);
	vi sons;
	for (int i = 0; i < sz(v); ++i) {
		int j = v[i];
		if (d[root][j] == 1) {
			ans.pb(mp(v[i], root));
			sons.pb(v[i]);
			swap(v.back(), v[i]);
			v.ppb();
			i--;
		}
	}
/*
	cerr << root << endl;
	for (auto x : sons)
		cerr << x << ' ';
	cerr << endl;
	for (auto x : v)
		cerr << x << ' ';
	cerr << endl;*/


	for (int i = 0; i < sz(sons) - 1; ++i) {
		if (!sz(v))
			break;

		int son = sons[i];
		ask(son);
		vi vv;
		for (int i = 0; i < sz(v); ++i)
			if (d[root][v[i]] - 1 == d[son][v[i]]) {
				vv.pb(v[i]);
				swap(v[i], v.back());
				v.ppb();
				--i;
			}

		solve(son, vv);
	}

	d[sons.back()][sons.back()] = 0;
	for (auto x : v)
		d[sons.back()][x] = d[root][x] - 1;

	solve(sons.back(), v);	
}

main () {
	memset(d, -1, sizeof(d));
	fastio
	cin >> n;
	vi v;
	for (int i = 2; i <= n; ++i)
		v.pb(i);
	
	ask(1);
	solve(1, v);
	cout << "!" << endl;
	for (auto x : ans)
		cout << x.f << ' ' << x.s << endl;
		
	return 0;
} 