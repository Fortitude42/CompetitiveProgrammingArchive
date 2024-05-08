#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#define ll long long
#define pii pair < int, int >
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define sz(s) (int)s.size()
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 5000;
const int M = N + 14;
const int inf = 1e9;



int n, k, s[M];
short R[2][M], L[2][M], l, r, l1, r1;
ll p[M];

int main() {
	scanf("%d%d", &n, &k);
	for (short i = 1; i <= n; ++i) {
		scanf("%lld", &p[i]);
		p[i] += p[i - 1];
	}
	
	
	for (short i = 1; i <= k; ++i)
		scanf("%d", &s[i]);
		
	for (short i = 1; i <= n; ++i) {
		R[0][i] = i;
		L[0][i] = i;
	}
		
	for (short i = 1; i <= k; ++i) {
		for (l = 1; l <= n; ++l) {
			R[i & 1][l] = l;
			L[i & 1][l] = l;
		}

		l1 = 1;
		for (l = 1; l <= n; ++l) {
			while (p[l - 1] - p[l1 - 1] > s[i])
				++l1;

			R[i & 1][l1] = max(R[i & 1][l1], R[(i - 1) & 1][l]);
			L[i & 1][R[(i - 1) & 1][l]] = min(L[i & 1][R[(i - 1) & 1][l]], l1);
		}

		r1 = n;
		for (r = n; r > 0; --r) {
			while (p[r1] - p[r] > s[i])
				--r1;

			L[i & 1][r1] = min(L[i & 1][r1], L[(i - 1) & 1][r]);
			R[i & 1][L[(i - 1) & 1][r]] = max(R[i & 1][L[(i - 1) & 1][r]], r1);
		}

		for (l = 2; l <= n; ++l)
			R[i & 1][l] = max(R[i & 1][l], R[i & 1][l - 1]);

		for (r = n - 1; r > 0; --r) 
			L[i & 1][r] = min(L[i & 1][r + 1], L[i & 1][r]);			
	}
	
	if (R[k & 1][1] == n) {
		printf("Yes");
		return 0;
	}
	printf("No");
	return 0;
}
