#include<bits/stdc++.h>
using namespace std;

#define int long long
const int P[] = {2,3,5,7,11,13,17,67,24251};
int mul(int A , int B , int P){int C = A * B - (int)((double)A * B / P + 0.1) * P; return C < 0 ? C + P : C;}
int poww(int a , int b , int p){int tms = 1; while(b){if(b & 1) tms = mul(tms , a , p); a = mul(a , a , p); b >>= 1;} return tms;}
bool MR(int x){
	for(int i = 0 ; i < 9 ; ++i) if(x == P[i]) return 1; else if(x % P[i] == 0) return 0;
	int cnt = x - 1 , num = 0; while(cnt % 2 == 0){++num; cnt >>= 1;}
	for(int i = 0 ; i < 9 ; ++i){
		int val = poww(P[i] , cnt , x); if(val == 1) continue;
		for(int j = 0 ; j < num && val != x - 1 ; ++j) val = mul(val , val , x);
		if(val != x - 1) return 0;
	}
	return 1;
}
struct base{
	int val[50] , sz; base(){memset(val , 0 , sizeof(val)); sz = 0;}
	void ins(int x){for(int i = 49 ; ~i ; --i) if(x >> i & 1) if(val[i]) x ^= val[i]; else{val[i] = x; ++sz; return;}}
};
base solve(int L , int R){
	base T; for(int i = R ; i >= max(L , R - (1 << 14)) ; --i) if(MR(i)) {T.ins(i);}
	if(R - L <= (1 << 14)) return T;
	for(int i = 49 ; ~i ; --i)
		if((L >> i & 1) != (R >> i & 1)){
			int p = (R >> i << i) - 1; while(p >= L && !MR(p)) --p;
			if(p >= L) T.ins(p);
			for(int j = i - 1 ; j > 0 ; --j) T.ins(1ll << j);
			T.ins((L >> i << i) | 1);
		}
	return T;
}

signed main(){
	int T , L , R;
	for(cin >> T ; T ; --T){
		cin >> L >> R;
		if(R - L <= (1 << 14)){base T = solve(L , R); cout << (1ll << T.sz) << endl;}
		else
			for(int i = 49 ; ~i ; --i)
				if((L >> i & 1) != (R >> i & 1)){
					int mid = (R >> i << i) - 1;
					base P = solve(L , mid) , Q = solve(mid + 1 , R);
					for(int i = 0 ; i < 50 ; ++i) if(Q.val[i]) P.ins(Q.val[i]);
					cout << (1ll << P.sz) << endl; break;
				}
	}
	return 0;
}