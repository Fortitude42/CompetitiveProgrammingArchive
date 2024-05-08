#pragma GCC optimize("Ofast")
 
#include <iostream>
#include <algorithm>
 
#define ll long long
#define ld long double
#define X first
#define Y second
#define MP make_pair
 
using namespace std;
 
const int N = 2e5 + 2, K = 700, K2 = 400;
const ll INF = 1e18;
const ll mod = 1e9 + 7;
 
int n, q, p[N], bp[N];
ll tb[N];
 
namespace BIT {
	ll a[N], b[N];
	void upd(int l, ll x) {
		int tl = l / K2;
		a[l] += x, b[tl] += x;
	}
	ll get(int l, int r) {
		if(r < l)
			return 0;
		int tl = l / K2, tr = r / K2;
		ll res = 0;
		if(tl != tr) {
			for(int i = l;i < tl * K2 + K2;i++)
				res += a[i];
			for(int i = tl + 1;i < tr;i++)
				res += b[i];
			for(int i = tr * K2;i <= r;i++)
				res += a[i];	
		}
		else {
			for(int i = l;i <= r;i++)
				res += a[i];
		}
		return res;
	}
}
 
void build(int id) {	
	int l = id * K, r = min(id * K + K, n);
	for(int i = l;i < r;i++)
		bp[i] = p[i];
	sort(bp + l, bp + r);
}
 
void push(int id) {
	int l = id * K, r = min(id * K + K, n);
	for(int i = l;i < r;i++) {
		BIT::upd(p[i], tb[id]);
	}	
	tb[id] = 0;
}
 
void upd(int l, int r, ll x) {
	int tl = l / K, tr = r / K;
	if(tl != tr) {
		//push(tl), push(tr);
		for(int i = l;i < tl * K + K;i++)
			BIT::upd(p[i], x);
		for(int i = tl + 1;i < tr;i++)
			tb[i] += x;
		for(int i = tr * K;i <= r;i++)	
			BIT::upd(p[i], x);
	}
	else {
		//cerr << "WAS\n";
		//push(tl);
		for(int i = l;i <= r;i++)
			BIT::upd(p[i], x);
	} 		
}
 
ll get(int r) {
	if(r == -1)
		return 0;
	ll res = BIT::get(0, r);
	for(int i = 0, id = 0;i < n;i += K, id++) {
		int cnt = upper_bound(bp + i, bp + min(i + K, n), r) - (bp + i);
		res += cnt * tb[id];	
	}
	return res;
}
 
void upd2(int l, int r) {
	push(l / K), push(r / K);
	//swap(p[l], p[r]);
	int x = p[l], y = p[r];
	swap(p[l], p[r]);
	int tl = l / K, tr = r / K;
	for(int i = tl * K;i < tl * K + K;i++)
		if(bp[i] == x) {
			bp[i] = y;
			for(int j = i - 1;j >= tl * K;j--) {
				if(bp[j] > bp[j + 1])
					swap(bp[j], bp[j + 1]);
			}
			for(int j = i;j + 1 < min(tl * K + K, n);j++) {
				if(bp[j] > bp[j + 1])
					swap(bp[j], bp[j + 1]);
			}
			break;
		}
	for(int i = tr * K;i < tr * K + K;i++)
		if(bp[i] == y) {
			bp[i] = x;
			for(int j = i - 1;j >= tr * K;j--) {
				if(bp[j] > bp[j + 1])
					swap(bp[j], bp[j + 1]);
			}
			for(int j = i;j + 1 < min(tr * K + K, n);j++) {
				if(bp[j] > bp[j + 1])
					swap(bp[j], bp[j + 1]);
			}
			break;
		}
 
	//build(l / K), build(r / K);
}
 
int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n >> q;
	for(int i = 0;i < n;i++)
		cin >> p[i], p[i]--;
	for(int i = 0, j = 0;i < n;i += K, j++)
		build(j);
	for(int tq, l, r, x;q--;) {
		cin >> tq >> l >> r, l--, r--;
		if(tq == 1) {
			cin >> x;
			upd(l, r, x);
		}
		else if(tq == 2) {
			cout << get(r) - get(l - 1) << "\n";	
		}
		else {
			upd2(l, r);
		}
	}
}