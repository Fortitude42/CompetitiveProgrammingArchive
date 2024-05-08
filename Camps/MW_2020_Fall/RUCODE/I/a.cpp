#include <bits/stdc++.h>
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int N = 2e6;

const int K = 30;

int n, X, a[10], k, b[N];
bitset<1 << K> w[2];

int f(int a, int b){
	int c = 0;
	int x = 0;
	for(int i = 0; i < K; i++){
		x = (x << 1) | ((b >> i) & 1);
		c |= ((__builtin_popcount(x & a) & 1) << i);
	}
	return c;
} 
void g1(int x, int i = 0){
	if(w[0][x])
		return;
	w[0][x] = 1;
	b[k++] = x;
	g1(f(x, a[i]), i);
	if(i + 1 < n / 2)
    	g1(x, i + 1);
}
bool g3(int x, int y, int i = 0){
	if(x == y)
		return 1;
	if(w[0][x])
		return 0;
	w[0][x] = 1;
	if(g3(f(x, a[i]), y, i)){
		cout << (char)('a' + i);
		return 1;
	}
	


	if(i + 1 < n / 2)
    	return g1(x, i + 1);
	return 0;
}
bool g2(int x, int i = 0){
	if(w[1][x])
		return 0;
	w[1][x] = 1;
	
	if(i == n - 1){
		for(int i = 0; i < k; i++)
			if(f(x, b[i]) == X){
				w[0].reset();
				g3(1, b[i]);        
				return 1;
			}
	}
	
	if(g2(f(x, a[i]), y, i)){
		cout << (char)('a' + i);
		return 1;
	}
	
	if(i + 1 < n)
    	return g2(x, i + 1);
	
	return 0;
}
int main()
{
	srand(time(0));
	cin >> n >> X;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < K; j++)
			a[i] |= ((rand() & 1) << j);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	g1(1);
	if(!g2(1))
		cout << "impossible" << endl;
}