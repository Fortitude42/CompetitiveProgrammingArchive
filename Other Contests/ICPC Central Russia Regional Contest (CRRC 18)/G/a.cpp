
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define y1 y1234567890

#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define file_io(s) freopen((s)".in", "r", stdin); freopen((s)".out", "w", stdout)

const int N = 1e3;
const int M = N + 7;
const double EPS = 1e-10;

const int K = 10;

const int MOD = (1ll << 60);
const ll INF = 2e18;


int n, m, nxt[N], good[N+N]; 
string s;
int k;
 
 
int f(int x, int y, char c) {
    if (c == '&')
        return (x & y);
 
    if (c == '|')
        return (x | y);
 
    if (c == '+')
        return (x ^ y); 
 
    return y;
}
 
 
bool check(int l, int r, int mask) {
    int res = -1;
    char sign = '#';
    bool neg = 0;
 
    while (l <= r) {
        if (s[l] == '(') {
            int x = nxt[l];
            int cur = check(l + 1, x - 1, mask);
            l = x + 1;
            res = f(res, (cur ^ neg), sign);            
            neg = 0;
            continue;
        }
 
        if (s[l] == '&' || s[l] == '|' || s[l] == '+') {
            sign = s[l++];
            neg = 0;
            continue;
        }
 
        if (s[l] == '-') {
            neg = 1;
            l++;
            continue;
        }
 
        int x = s[l++] - '0';
        x = (mask >> x) & 1;
        res = f(res, (x ^ neg), sign);
        neg = 0;
    }
 
    return res;
}
 
void build() {
    cin >> n >> s;
    m = sz(s);

    k = 0;
 
    stack < int > st;
    for (int i = 0; i < m; ++i) {
        if (s[i] == '(')
            st.push(i);
        else if (s[i] == ')') {
            nxt[st.top()] = i;
            st.pop();
        } else if (s[i] >= '0' && s[i] <= '9') {
            k = max(k, s[i] - '0' + 1);
        }
    }
 
    for (int mask = 0; mask < (1 << k); ++mask) {
        good[mask] = check(0, m - 1, mask);      
    }
 
}


ll dp[M][(1 << K) + 7];

int add(const int &a, const int &b) {
    return a + b + (a + b >= MOD ? -MOD : 0);
}

void solve() {
    build();
    for (int mask = 0; mask < (1 << k); mask++) {
        dp[k][mask] = good[mask];
    }

    for (int i = k; i < n; i++) {
        for (int mask = 0; mask < (1 << k); mask++) {
            if (!dp[i][mask])
                continue;

            int nxt = (mask << 1) & ((1 << k) - 1);
            if (good[nxt])
                dp[i + 1][nxt] = add(dp[i + 1][nxt], dp[i][mask]);
            if (good[nxt ^ 1])
                dp[i + 1][nxt ^ 1] = add(dp[i + 1][nxt ^ 1], dp[i][mask]);
        }
    }

    ll ans = 0;
    for (int mask = 0; mask < (1 << k); mask++)
        ans = add(ans, dp[n][mask]);

    cout << ans << "\n";
}

main() {
    fast_io;
    int tt = 1;
    // scanf("%d", &tt);
    while (tt--) {
        solve();
    }
    return 0;
}