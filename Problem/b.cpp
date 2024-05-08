#include <bits/stdc++.h>

using namespace std;

main () {
	int n;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int ok = 1;
		for (int j = 2; j < i; ++j)
			if (i % j == 0) 
				ok = 0;
		

		if (ok)
			cout << i << ' ';
	}

}