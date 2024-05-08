//2015 ACM-ICPC World Finals Problem. M
//O(operationnumber^3)
#include<bits/stdc++.h>
using namespace std;

struct rect{
	int x1 , y1 , x2 , y2;
	rect(int _x1 = 0 , int _y1 = 0 , int _x2 = 0 , int _y2 = 0) : x1(_x1) , y1(_y1) , x2(_x2) , y2(_y2){}
	friend bool sectx(rect p , rect q){return max(p.x1 , q.x1) <= min(p.x2 , q.x2);}
	friend bool secty(rect p , rect q){return max(p.y1 , q.y1) <= min(p.y2 , q.y2);}
	friend bool sect(rect p , rect q){return sectx(p , q) && secty(p , q);}
}now[257]; bool del[257]; int cnt , commandnumber , W , H;

void outputerror(string errorname , int errortype){
	cout << "Command " << commandnumber << ": " << errorname << " - ";
	if(errortype == 1) cout << "window does not fit" << endl;
	else cout << "no window at given position" << endl;
}

int select(int x , int y){
	rect tmp(x , y , x , y); for(int i = 1 ; i <= cnt ; ++i) if(!del[i] && sect(tmp , now[i])) return i;
	return 0;
}

void swapxy(){swap(W , H); for(int i = 1 ; i <= cnt ; ++i){swap(now[i].x1 , now[i].y1); swap(now[i].x2 , now[i].y2);}}
void shiftx(){for(int i = 1 ; i <= cnt ; ++i){swap(now[i].x1 , now[i].x2); now[i].x2 = W - 1 - now[i].x2; now[i].x1 = W - 1 - now[i].x1;}}

int main(){
	cin >> W >> H; string op; 
	while(cin >> op){
		++commandnumber;
		if(op[0] == 'O'){
			int x , y , w , h; cin >> x >> y >> w >> h;
			rect tmp(x , y , x + w - 1 , y + h - 1); if(tmp.x2 >= W || tmp.y2 >= H){outputerror(op , 1); continue;}
			bool f = 1; for(int i = 1 ; i <= cnt ; ++i) if(!del[i] && sect(tmp , now[i])) f = 0;
			if(f) now[++cnt] = tmp; else{outputerror(op , 1); continue;}
		}
		if(op[0] == 'C'){int x , y; cin >> x >> y; int t = select(x , y);
		if(!t){outputerror(op , 2); continue;} else del[t] = 1;}
		if(op[0] == 'R'){
			int x , y , w , h; cin >> x >> y >> w >> h; int t = select(x , y); if(!t){outputerror(op , 2); continue;}
			rect tmp(now[t].x1 , now[t].y1 , now[t].x1 + w - 1 , now[t].y1 + h - 1); if(tmp.x2 >= W || tmp.y2 >= H){outputerror(op , 1); continue;}
			bool f = 1; for(int i = 1 ; i <= cnt ; ++i) if(i != t && !del[i] && sect(tmp , now[i])) f = 0;
			if(f) now[t] = tmp; else{outputerror(op , 1); continue;}
		}
		if(op[0] == 'M'){
			int x , y , w , h; cin >> x >> y >> w >> h; int t = select(x , y); if(!t){outputerror(op , 2); continue;}
			bool f1 = w == 0; if(f1){swap(w , h); swapxy();}
			bool f2 = w < 0; if(f2){w = -w; shiftx();}

			static int dst[257]; memset(dst , 0x3f , sizeof(dst)); dst[t] = 0;
			static bool in[257]; memset(in , 0 , sizeof(in)); int mndst = 1e9;
			while(1){
				int mnid = 0; for(int j = 1 ; j <= cnt ; ++j) if(!in[j] && !del[j] && dst[mnid] > dst[j]) mnid = j;
				if(dst[mnid] > min(mndst , w)) break;
				mndst = min(mndst , dst[mnid] + W - 1 - now[mnid].x2); in[mnid] = 1;
				for(int j = 1 ; j <= cnt ; ++j)
					if(!in[j] && secty(now[mnid] , now[j]) && now[mnid].x2 < now[j].x1)
						dst[j] = min(dst[j] , dst[mnid] + now[j].x1 - now[mnid].x2 - 1);
			}
			if(w > mndst){cout << "Command " << commandnumber << ": " << op << " - moved " << mndst << " instead of " << w << endl; w = mndst;}
			for(int i = 1 ; i <= cnt ; ++i) if(in[i]){now[i].x1 += w - dst[i]; now[i].x2 += w - dst[i];}
			if(f2) shiftx();
			if(f1) swapxy();
		}
	}
	int num = 0; for(int i = 1 ; i <= cnt ; ++i) num += !del[i];
	cout << num << " window(s):" << endl;
	for(int i = 1 ; i <= cnt ; ++i)
		if(!del[i])
			cout << now[i].x1 << ' ' << now[i].y1 << ' ' << now[i].x2 - now[i].x1 + 1 << ' ' << now[i].y2 - now[i].y1 + 1 << endl;
	return 0;
}