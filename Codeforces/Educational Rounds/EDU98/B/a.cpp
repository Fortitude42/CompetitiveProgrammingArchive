#include <bits/stdc++.h>


using namespace std;

const int N = 102;
int n;
string s[N];
bool ok = 0;

int main () {
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> s[i];

	for (int i = 1; i <= n; ++i) {
		int cnt = 0;
		for (int j = 1; j < i; ++j)
			if (s[i] == s[j])
				++cnt;

		if (cnt == 1) {
			cout << s[i] << endl;
			ok = 1;
		}
	}

	if (ok == 0)
		cout << "Understandable, have a great day\n";
}