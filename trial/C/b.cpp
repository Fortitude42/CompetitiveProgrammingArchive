#include <bits/stdc++.h>

using namespace std;
const int N = 1.2e6 + 11;

struct Person {
	string name, num;
	int rub;
};

bool cmp (Person a, Person b) {
	if (a.rub != b.rub)
		return a.rub > b.rub;
	if (a.name != b.name)	
		return a.name < b.name;
	return a.num < b.num;
}

int n;
Person a[N];



int main () {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].name >> a[i].num >> a[i].rub;

	sort(a, a + n, cmp);
	for (int i = 0; i < min(n, 10); ++i) 
		cout << a[i].name << ' ' << a[i].num << ' ' << a[i].rub << endl;
	
}   	