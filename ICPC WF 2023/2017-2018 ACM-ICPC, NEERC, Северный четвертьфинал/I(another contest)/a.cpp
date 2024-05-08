#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
using namespace std;
using ll = long long;
const int N = 1e5 + 5, mod = 1e9 + 7;
const int base[] = {37, 41}, Mod[] = {(int)1e9 + 7, (int)1e9 + 9};
void add(int &x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}
int n, x, ct[51], f[N], r[N];
struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};
map <pair <int, int>, int> dp[51];
int bp(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = ans * 1ll * a % mod;
		a = a * 1ll * a % mod;
		b >>= 1;
	}
	return ans;
}
int A(int n, int k) {
	return f[n] * 1ll * r[n - k] % mod;
}
int zeroes;
vector <int> v;
int rec(int sum, int cnt) {
	if (sum >= 50 || cnt == n - zeroes)
		return f[(n - zeroes) - cnt];
	pair <int, int> h;
	for (int i = 0; i <= 50; ++i) {
		h.f = (h.f * 1ll * base[0] % Mod[0] + v[i]) % Mod[0];
		h.s = (h.s * 1ll * base[1] % Mod[1] + v[i]) % Mod[1];
	}
	if (dp[sum].count(h))
		return dp[sum][h];
	int res = 0;
	for (int x = sum; x > 0; x--) {
		if (v[x] < ct[x]) {
			++v[x];
			add(res, rec(sum + x, cnt + 1) * 1ll * (ct[x] - v[x] + 1) % mod);
			--v[x];
		}
	}
	return dp[sum][h] = res;
}
int main() {
	ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> x;
	f[0] = r[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int y;
		cin >> y;
		++ct[y];
		zeroes += (!y);
		f[i] = f[i - 1] * 1ll * i % mod;
		r[i] = bp(f[i], mod - 2);
	}
	v.resize(51);	
	cout << rec(x, 0) * 1ll * A(n, zeroes) % mod;
	return 0;
}
