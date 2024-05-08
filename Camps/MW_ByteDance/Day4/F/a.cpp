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

#define F first
#define S second

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

const int N = 255;

int n, A, B, C, D;
ld ad[N][N], abd[N][N], acd[N][N], abcd[N][N][N];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	cin >> n >> A >> B >> C >> D;

	ad[0][0] = 1.0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; i + j <= n; j++) {
			if (i) ad[i][j] += ad[i - 1][j] * A / 100.0;
			if (j) ad[i][j] += ad[i][j - 1] * D / 100.0;
			int len = n - i - j;
			for (int k = 0; k < len; k++) {
				abd[k][len - k] = max(abd[k][len - k], ad[i][j] * B / 100.0);
				acd[k][len - k] = max(acd[k][len - k], ad[i][j] * C / 100.0);
			}
		}
	}
	
	for (int sum = 0; sum <= n; sum++) {
		for (int i = 0; i <= sum; i++) {
			int j = sum - i;
			if (i) {
				abd[i][j] += abd[i - 1][j] * A / 100.0;
				acd[i][j] += acd[i - 1][j] * A / 100.0;
			}
			if (j) {
				abd[i][j] += abd[i][j - 1] * D / 100.0;
				acd[i][j] += acd[i][j - 1] * D / 100.0;
			}
			if (i && j) {
				abd[i][j] += max(abd[i - 1][j], abd[i][j - 1]) * B / 100.0;			
				acd[i][j] += max(acd[i - 1][j], acd[i][j - 1]) * C / 100.0;
			}
			else if (i) {
				abd[i][j] += abd[i - 1][j] * B / 100.0;			
				acd[i][j] += acd[i - 1][j] * C / 100.0;
			}
			else {
				abd[i][j] += abd[i][j - 1] * B / 100.0;			
				acd[i][j] += acd[i][j - 1] * C / 100.0;
			}
			for (int k = 0; k < j; k++)
				abcd[i][k][j - k] = max(abcd[i][k][j - k], abd[i][j] * C / 100.0);
			for (int k = 0; k < i; k++)
				abcd[k][i - k][j] = max(abcd[k][i - k][j], acd[i][j] * B / 100.0);
		}
	}

	for (int sum = 0; sum <= n; sum++) {
		for (int i = 0; i <= sum; i++) {
			for (int j = 0; i + j <= sum; j++) {
				int k = sum - i - j;
				if (i) abcd[i][j][k] += abcd[i - 1][j][k] * A / 100.0;
				if (k) abcd[i][j][k] += abcd[i][j][k - 1] * D / 100.0;
				if (i && j)
					abcd[i][j][k] += max(abcd[i - 1][j][k], abcd[i][j - 1][k]) * B / 100.0;
				else if (i)
					abcd[i][j][k] += abcd[i - 1][j][k] * B / 100.0;
				else
					abcd[i][j][k] += abcd[i][j - 1][k] * B / 100.0;
				if (j && k)
					abcd[i][j][k] += max(abcd[i][j - 1][k], abcd[i][j][k - 1]) * C / 100.0;
				else if (j)
					abcd[i][j][k] += abcd[i][j - 1][k] * C / 100.0;
				else
					abcd[i][j][k] += abcd[i][j][k - 1] * C / 100.0;
			}
		}
	}

	ld ans = 0.0;
	for (int i = 0; i <= n; i++) {
		ans += abd[i][n - i] + acd[i][n - i] + ad[i][n - i];
		for (int j = 0; i + j <= n; j++)
			ans += abcd[i][j][n - i - j];
	}
	cout << ans;

	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
