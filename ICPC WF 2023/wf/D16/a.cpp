#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pii = pair <int, int>;
using vi = vector <int>;


int n;

char c[101][8][22];
char s[60*24 + 2][8][22];
char ans[8][22], res[8][22];
bool seg[8][22];

int dx[4] = {0, 5, 12, 17};

vector < vector < pii > > p = {
		{mp(0, 1), mp(0, 2)},
		{mp(1, 0), mp(2, 0)},
		{mp(1, 3), mp(2, 3)},
		{mp(3, 1), mp(3, 2)},
		{mp(4, 0), mp(5, 0)},
		{mp(4, 3), mp(5, 3)},
		{mp(6, 1), mp(6, 2)},
	};
	
	vector < vi > pp = {
		{0, 1, 2, 4, 5, 6},
		{2, 5},
		{0, 2, 3, 4, 6},
		{0, 2, 3, 5, 6},
		{1, 2, 3, 5},
		{0, 1, 3, 5, 6},
		{0, 1, 3, 4, 5, 6},
		{0, 2, 5},
		{0, 1, 2, 3, 4, 5, 6},
		{0, 1, 2, 3, 5, 6}
	};
	
bool ok;

void check(int st) {
	for (int x = 0; x < 7; ++x)
		for (int y = 0; y < 7; ++y)
			res[x][y] = '.';
	for (int x = 0; x < 7; ++x)
		for (int y = 0; y < 21; ++y) {
			bool se = 1, ce = 1;
			bool sov = 1;
			
			for (int i = 0; i < n; ++i) {
				int t = (i + st) % (24*60);
				se &= s[t][x][y] == s[st][x][y];
				ce &= c[i][x][y] == c[0][x][y];
				sov &= s[t][x][y] == c[i][x][y];
			}

			if (ce && sov) {

				res[x][y] = !seg[x][y] ? '.' :'?';
				continue;
			}

			if (ce) {
				res[x][y] = '0' + (c[0][x][y] == 'X');
				continue;
			}

			if (sov) {
				res[x][y] = 'W';
				continue;
			}
			
			return;
		}

	ok = 1;
	for (int x = 0; x < 7; ++x)
		for (int y = 0; y < 21; ++y) {
			if (res[x][y] == '.')
				continue;
			if (res[x][y] == '?' || ans[x][y] == '?') {
				ans[x][y] = '?';
				continue;
			}

			assert(ans[x][y] == '.' || ans[x][y] == res[x][y]);

			ans[x][y] = res[x][y];
		}

	return;
	
}

int main() {
	ios :: sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n;
		
	for (int i = 0; i < n; ++i) {
		for (int x = 0; x < 7; ++x)
			for (int y = 0; y < 21; ++y)
				cin >> c[i][x][y];
	}

	for (int x = 0; x < 7; ++x)
		for (int y = 0; y < 21; ++y)
			ans[x][y] = '.';
	
	
	for (int st = 0; st < 60*24; ++st) {
		int h = st / 60;
		int m = st % 60;
		
		vector < int > ds;
		ds.pb(h / 10);
		ds.pb(h % 10);
		ds.pb(m / 10);
		ds.pb(m % 10);
				
		
		for (int x = 0; x < 7; ++x)
			for (int y = 0; y < 21; ++y)
				s[st][x][y] = '.';
				
				
		int i = 0;
		for (int d : ds) {
			if (i > 0 || d > 0) {
				for (auto id : pp[d]) {
					for (auto cor : p[id]) {
						s[st][cor.f][cor.s + dx[i]] = 'X';						
					}
				}
			}

			for (int id = 0; id < 7; ++id)
				for (auto cor : p[id])
					seg[cor.f][cor.s + dx[i]] = 1;
			++i;
		}		
		
		s[st][2][10] = 'X';
		s[st][4][10] = 'X';
		seg[2][10] = seg[4][10] = 1;

	}

	
	for (int st = 0; st < 60*24; ++st) {
		check(st);
	}

	if (ok) {
		for (int x = 0; x < 7; ++x, cout << endl)
			for (int y = 0; y < 21; ++y)
				cout << ans[x][y];		
	} else
		cout << "impossible";
	return 0;
}
