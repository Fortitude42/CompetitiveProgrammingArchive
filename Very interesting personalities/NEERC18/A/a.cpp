//by paradox & gege & parasat
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
const int N = 1e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;
const int K = 5;

int forSet[] = {0, 25, 25, 25, 25, 15};

int n, m;
pii p[K + 1];
int winner[M];

int ansScore, ansSet;
pii ansRes;
pii ans[K + 1];

void saveAnswer(int setn, int wina, int winb) {
	if (ansScore >= wina - winb)
		return;

	ansScore = wina - winb;
	ansSet = setn;
	ansRes = {wina, winb};
	for (int i = 1; i <= setn; i++)
		ans[i] = p[i];
}

void isThisGame(int setn, int wina, int winb, int tie = 0) {
	int tieSet = 0;
	int pa = n, pb = m;
	for (int i = 1; i <= setn; i++) {
		p[i].fi = (winner[i] == 1 ? forSet[i] : 0);
		p[i].se = (winner[i] == 2 ? forSet[i] : 0);

		if (tie && winner[i] == tie) {
			if (tie == 1)
				p[i].se = forSet[i] - 2;
			else
				p[i].fi = forSet[i] - 2;
			tie = 0;
			tieSet = i;
		}
		pa -= p[i].fi;
		pb -= p[i].se;
	}

	if (pa < 0 || pb < 0)
		return;
	
	if (tieSet) {
		int add = min(pa, pb);
		p[tieSet].fi += add;
		p[tieSet].se += add;
		pa -= add;
		pb -= add;
	}

	for (int i = 1; i <= setn; i++) {
		if (winner[i] == 1) {
			int add = min(p[i].fi - p[i].se - 2, pb);
			pb -= add;
			p[i].se += add;
		} else {
			int add = min(p[i].se - p[i].fi - 2, pa);
			pa -= add;
			p[i].fi += add;
		}
	}

	if (!pa && !pb)
		saveAnswer(setn, wina, winb);
}

void rec(int setn = 1, int wina = 0, int winb = 0) {
	if (wina == 3 || winb == 3) {
		isThisGame(setn - 1, wina, winb);
		if (wina)
			isThisGame(setn - 1, wina, winb, 1);
		if (winb)
			isThisGame(setn - 1, wina, winb, 2);
		return;
	}
	
	for (int i = 1; i <= 2; i++) {
		winner[setn] = i;
		rec(setn + 1, wina + (i == 1), winb + (i == 2));
		winner[setn] = 0;
	}
}

void solve() {
	scanf("%d %d", &n, &m);
	ansScore = -100;
	rec();

//	cerr << "Score: " << ansScore << "\n";
	if (ansScore == -100) {
		printf("Impossible\n");
		return;
	}
	printf("%d:%d\n", ansRes.fi, ansRes.se);
	for (int i = 1; i <= ansSet; i++)
		printf("%d:%d ", ans[i].fi, ans[i].se);
	printf("\n");
}

main () {
	int TT;
	TT = 1;
	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}                                                      