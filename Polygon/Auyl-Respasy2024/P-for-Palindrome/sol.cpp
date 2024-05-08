#include <bits/stdc++.h>                                           
#define sz(s) (int)s.size()

using namespace std;

 
const int M = 1e5 + 12;

string s;
int k, cnt[M][26];
 
void solve() {
	cin >> s >> k;
	for (int i = 0; i < sz(s); ++i)
		++cnt[i % k][s[i] - 'a'];

	for (int i = 0, j = sz(s) - 1; i < j; ++i, --j) {
		int ik = i % k;
		int jk = j % k;
		if (ik == jk) {
			bool found = 0;
			for (int x = 0; x < 26; ++x)
				if (cnt[ik][x] >= 2) {
					cnt[ik][x] -= 2;
					found = 1;
					break;
				}

			if (!found) {
				cout << "NO\n";
				return;
			}
		} else {
			bool found = 0;
			for (int x = 0; x < 26; ++x)
				if (cnt[ik][x] > 0 && cnt[jk][x] > 0) {
					--cnt[ik][x];
					--cnt[jk][x];
					found = 1;
					break;
				}

			if (!found) {
				cout << "NO\n";
				return;
			}			
		}
	}

	cout << "YES\n";
}

main () {
  int TT;
  TT = 1;
//  scanf("%d", &TT);
  for (int tt = 1; tt <= TT; ++tt) {
    solve();
  }
}