#include <iostream>

using namespace std;

int n, m;


int main () {
	cin >> n >> m;
	int a[n][m];
	for (int i = 0; i < n; ++i)  {
	    int cnt = 0;
		for (int j = 0; j < m; ++j) {
	    	cin >> a[i][j];
	    	if (a[i][j] < 0)
	    		++cnt;
	   	}
	   	cout << cnt << endl;
	}
}


