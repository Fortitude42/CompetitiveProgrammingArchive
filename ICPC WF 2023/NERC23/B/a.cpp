#include <bits/stdc++.h>
    
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
    
using namespace std;

const int mod = 998244353, N = (int)1e6 + 123;
   
ll fac[N];

ll bp(ll x, ll y) {
	ll z = 1;
	while (y) {
		if (y & 1)
			z = z * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return z;
}

ll fa(ll x) {
	return x * (x - 1) / 2;
}

ll fb(ll x) {
	return fa(x / 2) + fa(x - x / 2);
}

ll f(ll x, ll y, ll z, ll k) {
	k--;
	if (y % k == 0) 
		return fa(x) + fa(z) + fb(y / k) * k;
	return fa(x) + fa(z) + fb(y / k + 1) * (y % k) + fb(y / k) * (k - y % k);
}

ll fc(ll x, ll y, ll k) {
	return f(y / 2, x, y - y / 2, k);
}

ll cnk(ll x, ll y) {
	if (x < y || y < 0)
		return 0;
	ll ans = 1;
	for (int i = x; i > x - y; i--)
		ans = ans * i % mod;
	return ans * bp(fac[y], mod - 2) % mod;	
}

ll get(ll x, ll y, ll z, ll k) {
	ll ans = 1;
	k--;
	if (y % k == 0)
		ans = 1;
	else {
		ans = cnk(k, y % k);
	} 	

	if (x != z)
		ans = ans * 2 % mod;
	return ans;	
}

void solve() {
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		if (n % 2 == 0)
			cout << fa(n / 2) + fa(n / 2) << " " << 1 << '\n';
		else
			cout << fa(n / 2) + fa(n / 2 + 1) << " " << 2 << '\n';	
		return;
	}


	int la = k - 1, ra = n - 2;

	while (ra - la > 100) {
		int ma = la + (ra - la) / 3;
		int mb = ra - (ra - la) / 3;
		if (fc(ma, n - ma, k) < fc(mb, n - mb, k))
			ra = mb;
		else 
			la = ma;
	}

	ll mn = (ll)2e18;
	for (int i = la; i <= ra; i++)
		mn = min(mn, fc(i, n - i, k));

	ll ans = 0;
	for (int i = la; i <= ra; i++) {
		if (fc(i, n - i, k) != mn)
			continue;
		ll cnt = get((n - i) / 2, i, (n - i) - (n - i) / 2, k);
		ans = (ans + cnt) % mod;
	}
	cout << mn << ' ' << ans << '\n';
}

int main() {
	fac[0] = 1;
	for (int i = 1; i <= (int)1e6; i++)
		fac[i] = fac[i - 1] * i % mod;

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--) 
        solve();
    return 0;
}