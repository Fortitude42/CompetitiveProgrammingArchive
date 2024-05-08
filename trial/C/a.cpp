#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 11;

int n;
pair < int, int > a[N];
set < pair < int, int > > q;

int main () {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first >> a[i].second;
		q.insert(make_pair(a[i].first, a[i].second));
	}

	sort(a, a + n);
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < j; ++i) {
			if (a[i].first + a[i].first == a[j].first && a[i].second + a[i].second == a[j].second)
				continue;

			if (q.count(make_pair(a[j].first - a[i].first, a[j].second - a[i].second))) {
				cout << "YES";
				return 0;
			}
				
		}
	}

	cout << "NO";
}   	