#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 1000000007;
const ll INF = 1e18;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}



void solve(int t) {
    int n, k;
    cin >> n >> k;
    if (n==0 and k==0) exit(0);
    cout << "Case #" << t << ": Katya's place can be ";
    int p, y;
    cin >> p >> y;
    vector<vector<int>> a(n,vector<int>(k));
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<k;j++) cin >> a[i][j];
    }
    vector<int> q(n);
    if (n==1)
    {
        cout << 1 << "." << "\n";
        return;
    }
    p--;
    vector<int> was(k+1);
    for (int Q=0;;Q++)
    {
        for (int i=0;i<n;i++)
        {
            if (i==p) continue;
            while (was[a[i][q[i]]]) q[i]++;
            was[a[i][q[i]]] = 1;
            if (a[i][q[i]]==y)
            {
                cout << k+1-min(Q*n+i+1,k) << "." << "\n";
                return;
            }
        }
    }
}

int main() {
//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    cout.precision(20);
    for (int i = 1;; i++) {
//        cout << "Case #" << i << endl;
        solve(i);
    }
}