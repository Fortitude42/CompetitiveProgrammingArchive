#include <bits/stdc++.h>
    
#define ll long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
    
using namespace std;
   
const int N = (int)2e5 + 123;

int n, q, rb[2][N];
ll a[2][N], sum[4];
set<int> s[2];
ll ta[2][4 * N], add[2][4 * N];
pair<int,int> t[2][4 * N];

void upd(int i, int v, int tl, int tr, int pos, int val) {
	if (tl == tr) {
		ta[i][v] = val;     
		return;
	}
	int tm = (tl + tr) >> 1;
	if (pos <= tm)
		upd(i, v + v, tl, tm, pos, val);
	else
		upd(i, v + v + 1, tm + 1, tr, pos, val);
	ta[i][v] = ta[i][v + v] + ta[i][v + v + 1];	
}

ll get(int i, int v, int tl, int tr, int l, int r) {
	if (tr < l || r < tl)
		return 0;
	if (l <= tl && tr <= r) 
		return ta[i][v];

	int tm = (tl + tr) >> 1;
	return get(i, v + v, tl, tm, l, r) + get(i, v + v + 1, tm + 1, tr, l, r);
}

void push(int i, int v) {
	if (add[i][v]) {
		t[i][v + v].first += add[i][v];
		t[i][v + v + 1].first += add[i][v];
		add[i][v + v] += add[i][v];
		add[i][v + v + 1] += add[i][v];
		add[i][v] = 0;
	}
}

void build(int i, int v, int tl, int tr) {
	if (tl == tr) {
		t[i][v] = {a[i][tl], tl};
		return;
	}
	int tm = (tl + tr) >> 1;
	build(i, v + v, tl, tm);
	build(i, v + v + 1, tm + 1, tr);
	t[i][v] = max(t[i][v + v], t[i][v + v + 1]);
}

void updmax(int i, int v, int tl, int tr, int l, int r) {
	if (tr < l || r < tl)
		return;
	if (l <= tl && tr <= r) {
		t[i][v].first++;
		add[i][v]++;
		return;
	}
	push(i, v);
	int tm = (tl + tr) >> 1;//tm
	updmax(i, v + v, tl, tm, l, r);
	updmax(i, v + v + 1, tm + 1, tr, l, r);
	t[i][v] = max(t[i][v + v], t[i][v + v + 1]);
}



pair<int, int> getmax(int i, int v, int tl, int tr, int l, int r) {
	if (tr < l || r < tl)
		return {-1, -1};
	if (l <= tl && tr <= r)
		return t[i][v];
	push(i, v);
	int tm = (tl + tr) >> 1;
	return max(getmax(i, v + v, tl, tm, l, r), getmax(i, v + v + 1, tm + 1, tr, l, r));//;
}

void UPD(int ind, int l, int r) {
	updmax(ind, 1, 0, n, l, r);
	auto it = s[ind].lower_bound(l);
	it--;
	int la = *it;
	int ra = rb[ind][la];

	
	pair<int, int> pr = getmax(ind, 1, 0, n, la, ra);
	int mxa = pr.second;
	if (mxa != la) {
		s[ind].insert(mxa);
		rb[ind][mxa] = rb[ind][la];
		rb[ind][la] = mxa - 1;
		upd(ind, 1, 0, n, la, rb[ind][la] - la + 1);
		upd(ind, 1, 0, n, mxa, rb[ind][mxa] - mxa + 1);
	}
	sum[ind] += get(ind, 1, 0, n, l, r);
	it = s[ind].upper_bound(r);
	it--;
	int i = *it;
	
	
	while (true) {
		it = s[ind].upper_bound(i);
		if (it == s[ind].end() || getmax(ind, 1, 0, n, *it, *it).first == getmax(ind, 1, 0, n, i, i).first) {
			int j = *it;
			s[ind].erase(j);
			upd(ind, 1, 0, n, j, 0);
			rb[ind][i] = rb[ind][j];
			upd(ind, 1, 0, n, i, rb[ind][i] - i + 1);
		}
	}
}

ll calc() {
	return sum[0] + sum[1] - sum[2] - sum[3] * n;
}



void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) { 
		cin >> a[0][i];
		a[1][n - i + 1] = a[0][i];
	}

	
	ll mx = 0;
	for (int j = 0; j < 2; j++) {
		mx = -1;
		for (int i = 0; i <= n; i++) {
			if (mx < a[j][i]) {
				int R = i;
				while (R < n && a[j][R + 1] <= a[j][i])
					R++;
				s[j].insert(i);
				upd(j, 1, 0, n, i, R - i + 1); 	
				mx = a[j][i];
				sum[j] += 1LL * (R - i + 1) * a[j][i];
				rb[j][i] = R;
				i = R;
			}                     
		}
	}
	for (int i = 0; i <= n; i++)
		sum[2] += a[0][i];
	sum[3] = mx;
	cout << calc() << '\n';
	while (q--) {
		int l, r;
		cin >> l >> r;
		UPD(0, l, r);
		UPD(1, n - r + 1, n - l + 1);
		cout << calc() << '\n';
	}
	
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    //cin >> tt;
    while (tt--) 
        solve();
    return 0;
}