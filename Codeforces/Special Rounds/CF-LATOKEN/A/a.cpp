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
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
const ll INF = 1e18;
const double pi = acos(-1);    
//fucking constants

queue < pii > q;
int t, n, m;
char c[N][N];

bool in (int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

main () {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				cin >> c[i][j];          
				if (c[i][j] != '.')
					q.push(mp(i, j));
			}

		if (!sz(q)) {
			q.push({0, 0}); 
			c[0][0] = 'R';
		}
		
		bool ok = 1;
		while (sz(q)) {
			int x = q.front().f, y = q.front().s;
			q.pop();

			for (int i = 0; i < 4; ++i) {
				int tox = x + dx[i], toy = y + dy[i];
				if (!in(tox, toy))
					continue;
				if (c[tox][toy] == c[x][y]) 
					ok = 0;
				if (c[tox][toy] == '.') {
					c[tox][toy] = (c[x][y] == 'R' ? 'W' : 'R');
					q.push(mp(tox, toy));
				}
			}
		}

		if (!ok) {
			cout << "NO" << endl;
			continue;
		}

		cout << "YES\n";
		for (int i = 0; i < n; ++i, cout << endl)
			for (int j = 0; j < m; ++j)
				cout << c[i][j];
	}
} 