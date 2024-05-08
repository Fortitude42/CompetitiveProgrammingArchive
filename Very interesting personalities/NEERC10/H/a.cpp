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
const int N = 4e5, inf = 1e9, MOD = 1e9 + 7;
const int M = N + 17;
const ll INF = 1e18;


string Rank = "23456789TJQKA";
string Suit = "CDHS";
map < char, int > R, S;

int cnt[M], cnt1[M], cnt2[M], cnt3[M], cnt4[M], cnt5[M], cnt6[M], cnt7[M], cnt8[M];
vector < pii > cards, cur;

int Four(const vector < pii > &x) {
	if (x[0].f == x[3].f)
		return x[0].f * 13 + x[4].f;

	if (x[1].f == x[4].f)
		return x[4].f * 13 + x[0].f;

	return -1;
}

int FullHouse(const vector < pii > &x) {
	if (x[0].f == x[2].f) {
		if (x[3].f == x[4].f)
			return x[0].f*13 + x[3].f;
		return -1;
	}

	if (x[0].f == x[1].f) {
		if (x[2].f == x[4].f)
			return x[2].f * 13 + x[0].f;
		return -1;
	}

	return -1;
}

int Flush(const vector < pii > &x) {
	for (int i = 1; i < sz(x); ++i)
		if (x[i].s != x[i - 1].s)
			return -1;

	int res = 0;
	for (int i = 0; i < sz(x); ++i)
		res = res * 13 + x[i].f;

	return res;
}

int Straight(const vector < pii > &x) {
	for (int i = 2; i < sz(x); ++i)
		if (x[i].f != x[i - 1].f - 1)
			return -1;

	if (x[0].f == 12 && x.back().f == 0)
		return x[1].f;
	if (x[0].f == x[1].f + 1)
		return x[0].f;
	return -1;
}



int StraightFlush(const vector < pii > &x) {
	int s = Straight(x);
	int f = Flush(x);
	if (s == -1 || f == -1)
		return -1;
	return s;
}

int Three(const vector < pii > &x) {
	for (int i = 0; i + 2 < sz(x); ++i)
		if (x[i].f == x[i + 2].f) {
			int res = x[i].f;
			for (int j = 0; j < sz(x); ++j)
				if (j != i && j != i + 1 && j != i + 2) 
					res = res * 13 + x[j].f;
			return res;					
		}

	
	return -1;
}

int Two(const vector < pii > &x) {
	for (int i = 0; i + 1 < sz(x); ++i)
		if (x[i].f == x[i + 1].f)
			for (int j = i + 2; j + 1 < sz(x); ++j)
				if (x[j].f == x[j + 1].f) 
					for (int k = 0; k < sz(x); ++k)
						if (k != i && k != i + 1 && k != j && k != j + 1)
							return 169 * x[i].f + 13 * x[j].f + x[k].f;
				
	return -1;
}

int Pair(const vector < pii > &x) {
	for (int i = 0; i + 1 < sz(x); ++i)
		if (x[i].f == x[i + 1].f) {
			int res = x[i].f;
			for (int j = 0; j < sz(x); ++j)
				if (i != j && j != i + 1)
					res = res * 13 + x[j].f;

			return res;
		}

	return -1;
}

int High(const vector < pii > &x) {
	int res = 0;
	for (int i = 0; i < sz(x); ++i)
		res = res * 13 + x[i].f;
	return res;
}

void rec(int i = 0) {
	if (sz(cur) == 5) {
		int c = StraightFlush(cur);
		
		if (c != -1) {
			cnt[c] = 1;
			return;
		}

		c = Four(cur);
		if (c != -1) {     
			cnt1[c] = 1;
			return;
		}

		c = FullHouse(cur);
		if (c != -1) {
			cnt2[c] = 1;
			return;
		}

		c = Flush(cur);
		if (c != -1) {
			cnt3[c] = 1;
			return;
		}


		c = Straight(cur);
		if (c != -1){
			cnt4[c] = 1;
			return;
		}

		c = Three(cur);
		if (c != -1) {
			cnt5[c] = 1;
			return;
		}
        
		c = Two(cur);
		if (c != -1) {
			cnt6[c] = 1;
			return;
		}
        
		c = Pair(cur);
		if (c != -1) {
			cnt7[c] = 1;
			return;
		}
		
		cnt8[High(cur)] = 1;
		return;
	}

	if (sz(cur) < 5) {
		cur.pb(cards[i]);
		rec(i + 1);
		cur.ppb();
	}

	if (sz(cur) + sz(cards) - i - 1 >= 5)
		rec(i + 1);
}


void precalc() {
	for (int i = 0; i < sz(Rank); ++i)
		for (int j = 0; j < sz(Suit); ++j)
			cards.pb({i, j});

	sort(all(cards));
	reverse(all(cards));

	rec();

	
	for (int i = 1; i < M; ++i) {		
		cnt3[i] += cnt3[i - 1];
		cnt7[i] += cnt7[i - 1];
		cnt8[i] += cnt8[i - 1];
		cnt6[i] += cnt6[i - 1]; 
		cnt5[i] += cnt5[i - 1];
		cnt1[i] += cnt1[i - 1];
		cnt2[i] += cnt2[i - 1];
		cnt[i] += cnt[i - 1];
		cnt4[i] += cnt4[i - 1];
	}

	for (int i = 0; i < sz(Rank); ++i)
		R[Rank[i]] = i;

	for (int i = 0; i < sz(Suit); ++i)
		S[Suit[i]] = i;
}
 
void solve() {
	vector < pii > cur;

	for (int i = 0; i < 5; ++i) {
		string a;
		cin >> a;
		cur.pb({R[a[0]], S[a[1]]});
	}
	sort(all(cur));
	reverse(all(cur));

	int tot = 7462;

	//StraightFlush	
	tot -= cnt[M - 1];
	int c = StraightFlush(cur);
	if (c != -1) {
		cout << tot + cnt[c] << endl;
		return;
	}


	//Four	
	tot -= cnt1[M - 1];
	c = Four(cur);
	if (c != -1) {
		cout << tot + cnt1[c] << endl;
		return;                                  
	}

	//FullHouse
	tot -= cnt2[M - 1];
	c = FullHouse(cur);
	if (c != -1) {
		cout << tot + cnt2[c] << endl;
		return;
	}

	//Flush
	tot -= cnt3[M - 1];
	c = Flush(cur);
	if (c != -1) {
		cout << tot + cnt3[c] << endl;
		return;
	}

	//Straight	
	tot -= cnt4[M - 1];
	c = Straight(cur);
	if (c != -1) {
		cout << tot + cnt4[c] << endl;
		return;
	}

	//Three
	tot -= cnt5[M - 1];
	c = Three(cur);
	if (c != -1) {
		cout << tot + cnt5[c] << endl;
		return;
	}

	//Two
	tot -= cnt6[M - 1];
	c = Two(cur);
	if (c != -1) {
		cout << tot + cnt6[c] << endl;
		return;
	}

	//Pair
	tot -= cnt7[M - 1];
	c = Pair(cur);
	if (c != -1) {
		cout << tot + cnt7[c] << endl;
		return;
	}

	//High	
	tot -= cnt8[M - 1];
	c = High(cur);
	if (c != -1) {
		cout << tot + cnt8[c] << endl;
		return;
	}
}

main () {
//    file("hands")
	int TT;
	TT = 1;
	precalc();
//	scanf("%d", &TT);
	for (int tt = 1; tt <= TT; ++tt) {
		solve();
	}
}

