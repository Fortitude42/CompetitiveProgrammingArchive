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
 
 
#define int long long	
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
   
   
const int N = 143, inf = 1e9, mod = 998244353;
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

int n, k, a[N][N], p[N][2], cnt[N][2];

int get (int v, int i) {
	return p[v][i] == v ? v : p[v][i] = get(p[v][i], i);
}

void merge (int v, int u, int i) {
	v = get(v, i);
	u = get(u, i);

	if (v == u)
		return;

	if (cnt[v][i] < cnt[u][i])	
		swap(v, u);

	cnt[v][i] += cnt[u][i];
	p[u][i] = v;
}


int f[N*N + N];
bool ok[N][N][2];

void precalc () {
	f[0] = 1;
	for (int i = 1; i < N*N; ++i)
		f[i] = f[i - 1] * i % mod;
}

main () {
	precalc();

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j < 2; ++j) {
			p[i][j] = i;
			cnt[i][j] = 1;
		}
			

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			cin >> a[i][j];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int x = j + 1; x <= n; ++x) {
				if (a[i][j] + a[i][x] > k) 
					ok[j][x][0] = 1;
				if (a[j][i] + a[x][i] > k)
					ok[j][x][1] = 1;
			}

	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
			for (int x = 0; x < 2; ++x)
				if (!ok[i][j][x])
					merge(i, j, x);

	int ans = 1;
	for (int i = 1; i <= n; ++i) 
		for (int j = 0; j < 2; ++j)
			if (p[i][j] == i)
				ans = ans * f[cnt[i][j]] % mod;

	cout << ans << endl;		
} 