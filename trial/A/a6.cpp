#include <iostream>

using namespace std;

string s;

int main () {
	cin >> s;
	int n = s.length();

	for (int i = 0; i < n; ++i) {
		int cnt1 = 0, cnt2 = 1;

		for (int j = 0; j < i; ++j)
			if (s[i] == s[j])
				++cnt1;

		for (int j = i + 1; j < n; ++j)
			if (s[i] == s[j])
				++cnt2;
		
		if (cnt1 == 0)
			cout << s[i] << ' ' << cnt2 << endl;
	}

}


