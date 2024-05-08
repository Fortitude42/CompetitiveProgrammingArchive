//https://codeforces.com/group/OxWQShaH6g/contest/103439/submission/137286543
const ll P[] = {2,3,5,7,11,13,17,67,24251};
ll mul(ll A , ll B , ll P){ll C = A * B - (ll)((double)A * B / P + 0.1) * P; return C < 0 ? C + P : C;}
ll poww(ll a , ll b , ll p){ll tms = 1; while(b){if(b & 1) tms = mul(tms , a , p); a = mul(a , a , p); b >>= 1;} return tms;}

bool MR (ll x){
	if (x <= 1)
		return 0;
	for(ll i = 0 ; i < 9 ; ++i) if(x == P[i]) return 1; else if(x % P[i] == 0) return 0;
	ll cnt = x - 1 , num = 0; while(cnt % 2 == 0){++num; cnt >>= 1;}
	for(ll i = 0 ; i < 9 ; ++i){
		ll val = poww(P[i] , cnt , x); if(val == 1) continue;
		for(ll j = 0 ; j < num && val != x - 1 ; ++j) val = mul(val , val , x);
		if(val != x - 1) return 0;
	}
	return 1;
}
