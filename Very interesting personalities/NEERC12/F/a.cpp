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
const int N = 15, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;

struct Item{
	int x, y, z, dir, mask;
	Item() {}

	Item(int X, int Y, int Z, int Dir, int Mask) {
		x = X;
		y = Y;
		z = Z;
		dir = Dir;
		mask = Mask;
	}
} empty = *new Item(-1, -1, -1, -1, -1);

bool turn[30];
char ans[3][3][3];
queue < Item > q;
map < char, pii > pos;
map < int, Item > p[3][3][3][3];
string alpha = "AaBbCcDdEeFfGgHhIiJjKkLlMmN";

bool in(int x, int y, int z) {
	return x >= 0 && y >= 0 && z >= 0 && x < 3 && y < 3 && z < 3;
}

int getBit(int x, int y, int z) {
	return (1 << (9*x + 3*y + z));
}
 
void solve() {
	for (int i = 0; i < 15; ++i)
		for (int j = 0; j < 15; ++j) {
			char c;
			cin >> c;
			if (c != '.')
				pos[c] = {i, j};
		}

	int prv = -1;
	for (int i = 0; i < sz(alpha); ++i) {
		int f = (i > 0 && pos[alpha[i]].f == pos[alpha[i - 1]].f);
		if (i > 1 && prv != f) {
			turn[i - 1] = 1; 
//			cerr << alpha[i - 1] << endl;
		}

		prv = f;
	}

	for (int x = 0; x < 2; ++x)
		for (int y = 0; y < 2; ++y)
			for (int z = 0; z < 1; ++z)
				for (int dir = 0; dir < 3; ++dir) {
					p[x][y][z][dir][getBit(x, y, z)] = empty;
					q.push(*new Item(x, y, z, dir, getBit(x, y, z)));
				}

	Item f = empty;
	while (sz(q)) {
		Item item = q.front();
		q.pop();

		int i = __builtin_popcount(item.mask) - 1;
		if (i == 26) {
			f = item;
			break;
		}

		for (int d = 0; d < 3; ++d) {
			if ((item.dir != d) != turn[i])
				continue;
			for (int x = -1; x <= 1; x += 2) {
				Item nItem = item;
				nItem.dir = d;
				if (!d)
					nItem.x += x;
				if (d == 1)
					nItem.y += x;
				if (d == 2)
					nItem.z += x;
				if (!in(nItem.x, nItem.y, nItem.z) || (item.mask & getBit(nItem.x, nItem.y, nItem.z)))
					continue;
				nItem.mask |= getBit(nItem.x, nItem.y, nItem.z);

				if (!p[nItem.x][nItem.y][nItem.z][nItem.dir].count(nItem.mask)) {
					p[nItem.x][nItem.y][nItem.z][nItem.dir][nItem.mask] = item;
					q.push(nItem);
				}
			}
		}
	}

	int i = 26;

	while (f.x > -1) {
		Item prv = p[f.x][f.y][f.z][f.dir][f.mask];
		ans[f.x][f.y][f.z] = alpha[i--];
		f = prv;
	}

	for (int i = 0; i < 3; ++i, cout << endl) {
		for (int j = 0; j < 3; ++j) {
			for (int x = 0; x < 3; ++x)
				cout << ans[i][j][x];
			if (j < 2)
				cout << ' ';
		}
	}
			

}

main () {
//	file("folding");
	int TT;
	TT = 1;
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

