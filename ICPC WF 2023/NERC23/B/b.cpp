#include <bits/stdc++.h>
    
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
    
using namespace std;

const int mod = 998244353, N = (int)1e6 + 123;

int n, k;   
ll mn = 1e18;
int cnt = 0;

ll f(int x) {
	return x*1ll*(x - 1) / 2;
}

ll ff(int x) {
	return f(x / 2) + f(x - x/2);
}

void rec(int s = 0, int i = 0, ll c = 0) {
	if (i == k) {
		c += ff(n - s);
		if (mn > c) {
			mn = c;
			cnt = 1;
		} else if (mn == c) {
			++cnt;
		}
		return;
	}

	for (int i = 1; i <= 
}

void solve() {
	cin >> n >> k;
	rec();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) 
        solve();
    return 0;
}