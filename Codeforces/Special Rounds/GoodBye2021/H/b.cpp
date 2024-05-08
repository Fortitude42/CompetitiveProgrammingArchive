/* http://usaco.org/index.php?page=viewproblem2&cpid=1070 */
#include <stdio.h>

#define N	150000
#define L	30
#define N_	(3 + N * (L + 1))
#define MD	998244353

int tt[N_][2], ww[N_], _;

void add(int a) {
	int l, t;

	for (l = L - 1, t = 1; l >= 0; l--) {
		int c = a >> l & 1;

		if (!tt[t][c])
			ww[tt[t][c] = ++_] = 1;
		t = tt[t][c];
		ww[t] = ww[t] * 2 % MD;
	}
}

int dfs(int t1, int t2, int l, int x) {
	if (t1 == 0)
		return ww[t2] - 1;
	if (t2 == 0)
		return ww[t1] - 1;
	if (l == -1)
		return (t1 == t2 ? ww[t1] - 1 : (long long) ww[t1] * ww[t2] - 1) % MD;
	if ((x & 1 << l) == 0) {
		int z00 = dfs(tt[t1][0], tt[t2][0], l - 1, x);
		int z11 = dfs(tt[t1][1], tt[t2][1], l - 1, x);

		if (t1 == t2)
			return (z00 + z11) % MD;
		else {
			int zt1 = (long long) (ww[tt[t1][0]] - 1) * (ww[tt[t1][1]] - 1) % MD;
			int zt2 = (long long) (ww[tt[t2][0]] - 1) * (ww[tt[t2][1]] - 1) % MD;

			return ((long long) z00 + z11 + zt1 + zt2) % MD;
		}
	} else {
		int z = t1 == t2 ? dfs(tt[t1][0], tt[t2][1], l - 1, x) : ((long long) (dfs(tt[t1][0], tt[t2][1], l - 1, x) + 1) * (dfs(tt[t1][1], tt[t2][0], l - 1, x) + 1) - 1) % MD;

		return z;
	}
}

int main() {
	int n, x, ans;

	scanf("%d%d", &n, &x);
	_ = 1, ww[0] = 1;
	while (n--) {
		int a;

		scanf("%d", &a);
		add(a);
	}
	ans = dfs(1, 1, L - 1, x);
	if (ans < 0)
		ans += MD;
	printf("%d\n", ans);
	return 0;
}
