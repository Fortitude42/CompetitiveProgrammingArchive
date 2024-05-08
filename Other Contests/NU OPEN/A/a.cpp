#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 11;

int n, q, l, r, x, tp;
long long t[N << 2], add[N << 2];

void push (int v, int tl, int tr, int tm) {
	if (add[v]) {
		add[v << 1] += add[v];
		add[v << 1 | 1] += add[v];

		t[v << 1] += add[v] * (tm - tl + 1);
		t[v << 1 | 1] += add[v] * (tr - tm);

		add[v] = 0;
	}
}

void update (int l, int r, int x, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return;
	if (l <= tl && tr <= r) {
		add[v] += x;
		t[v] += (tr - tl + 1) * 1ll * x;
		return;
	}

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	update(l, r, x, v << 1, tl, tm);
	update(l, r, x, v << 1 | 1, tm + 1, tr);
	t[v] = t[v << 1] + t[v << 1 | 1];
}

long long get (int l, int r, int v = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr)
		return 0;

	if (l <= tl && tr <= r)
		return t[v];

	int tm = (tl + tr) >> 1;
	push(v, tl, tr, tm);
	return get(l, r, v << 1, tl, tm) + get(l, r, v << 1 | 1, tm + 1, tr);
}

main () {
	scanf("%d%d", &n, &q);
	while (q--) {
		scanf("%d", &tp);
		if (tp == 1) {
			scanf("%d%d%d", &l, &r, &x);
			update(l, r, x);
		} else {
			scanf("%d%d", &l, &r);
			printf("%lld\n", get(l, r));
		}
	}
}