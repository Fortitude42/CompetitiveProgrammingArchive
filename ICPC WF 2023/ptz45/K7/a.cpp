#include <bits/stdc++.h>

#define int long long
#define pii pair < int, int >
#define ll long long
#define all(x) x.begin(), x.end()
#define pb push_back
#define vi vector < int >
#define sz(s) (int)s.size()
#define s second
#define f first
#define mp make_pair

using namespace std;

const int N = 300;
const int M = N + 15;

struct Point {
    int64_t x, y;

    Point(int64_t x_ = 0, int64_t y_ = 0): x(x_), y(y_) {}
    
    bool operator<(const Point &p) const {
		return tie(x,y) < tie(p.x,p.y);
	}
    

    Point operator - (const Point & p) const {
        return Point(x - p.x, y - p.y);
    }

    int64_t cross (const Point & p) const {
        return x * p.y - y * p.x;
    }
    
	ll dot (const Point &p) const {
		return x*p.x + y*p.y;
	}
	
    int64_t cross (const Point & p, const Point & q) const {
        return (p - *this).cross(q - *this);
    }

    bool half () const {
        return bool(y < 0 || (y == 0 && x < 0));
    }
};

vector<vector<int>> find_faces(vector<Point> vertices, vector<vector<int>> adj) {
    int n = vertices.size();
    std::vector<std::vector<char>> used(n);
    for (int i = 0; i < n; i++) {
        used[i].resize(adj[i].size());
        used[i].assign(adj[i].size(), 0);
        auto compare = [&](int l, int r) {
            Point pl = vertices[l] - vertices[i];
            Point pr = vertices[r] - vertices[i];
            if (pl.half() != pr.half())
                return pl.half() < pr.half();
            return pl.cross(pr) > 0;
        };
        std::sort(adj[i].begin(), adj[i].end(), compare);
    }
    std::vector<std::vector<int>> faces;
    for (int i = 0; i < n; i++) {
        for (int edge_id = 0; edge_id < (int)adj[i].size(); edge_id++) {
            if (used[i][edge_id]) {
                continue;
            }
            std::vector<int> face;
            int v = i;
            int e = edge_id;
            while (!used[v][e]) {
                used[v][e] = true;
                face.push_back(v);
                int u = adj[v][e];
                int e1 = std::lower_bound(adj[u].begin(), adj[u].end(), v, [&](int l, int r) {
                    Point pl = vertices[l] - vertices[u];
                    Point pr = vertices[r] - vertices[u];
                    if (pl.half() != pr.half())
                        return pl.half() < pr.half();
                    return pl.cross(pr) > 0;
                }) - adj[u].begin() + 1;
                if (e1 == (int)adj[u].size()) {
                    e1 = 0;
                }
                v = u;
                e = e1;
            }
            std::reverse(face.begin(), face.end());
            int sign = 0;
            for (int j = 0; j < (int)face.size(); j++) {
                int j1 = (j + 1) % face.size();
                int j2 = (j + 2) % face.size();
                int64_t val = vertices[face[j]].cross(vertices[face[j1]], vertices[face[j2]]);
                if (val > 0) {
                    sign = 1;
                    break;
                } else if (val < 0) {
                    sign = -1;
                    break;
                }
            }
            if (sign <= 0) {
                faces.insert(faces.begin(), face);
            } else {
                faces.emplace_back(face);
            }
        }
    }
    return faces;
}

ll polygonArea2(vector<Point>& v) {
	ll a = v.back().cross(v[0]);
	for (int i = 0; i < sz(v) - 1; ++i) 
		a += v[i].cross(v[i+1]);
	return a;
}


int n, m, e, id[M][M], inds[M];
vector < vi > compadj;
vector < int > g[M];
vector < Point > comp;
Point a[M], b[M];
bool used[M], was[M], ans[M];
map < pii, int > ID;
int t[M], timer, inid[M];

void dfs(int v) {
	used[v] = 1;	
	comp.pb(a[v]);
	compadj.pb({});
	inds[v] = sz(comp) - 1;
	
	for (auto to : g[v]) {
		if (!used[to])
			dfs(to);
			
		compadj[inds[v]].pb(inds[to]);
	}
}

bool onSegment(Point s, Point e, Point p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

bool inPolygon(vector<Point> &p, Point a, bool strict = true) {
	if (sz(p) < 3)
		return 0;

	int cnt = 0, n = sz(p);
	for (int i = 0; i < n; ++i) {
		Point q = p[(i + 1) % n];
		if (onSegment(p[i], q, a)) return !strict;
		//or : i f (segDist(p [ i ] , q , a) <= eps) return ! s t r i c t ;
		cnt ^= ((a.y<p[i].y) - (a.y<q.y)) * a.cross(p[i], q) > 0;
	}
	return cnt;
}

main() {
	cin >> n >> m >> e;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].y;
		ID[mp(a[i].x, a[i].y)] = i;
	}
		
	for (int i = 1; i <= m; ++i)
		cin >> b[i].x >> b[i].y;
		
	
	for (int i = 1; i <= e; ++i) {
		int v1, v2;
		cin >> v1 >> v2;
		id[v1][v2] = id[v2][v1] = i;
		g[v1].pb(v2);
		g[v2].pb(v1);
	}
	
	vector < pair < Point, int > > order;
	for (int i = 1; i <= n; ++i)
		order.pb(mp(a[i], i));
		
	sort(all(order));
	
	vector < vector < Point > > verts;
	vector < vector<vector<int>> > adjs;
	
	for (auto x : order) 		
		if (!used[x.s]) {
			comp.clear();
			compadj.clear();
			dfs(x.s);
			verts.pb(comp);
			adjs.pb(compadj);
		}
		
	reverse(all(verts));
	reverse(all(adjs));
	memset(inid, -1, sizeof inid);
		
	vector < vector<vector<Point>> > ifs, ofs;
	for (int i = 0; i < sz(verts); ++i) {
		vector<vector<int>> faces = find_faces(verts[i], adjs[i]);		
		vector<vector<Point>> ifaces, ofaces;
		
		for (auto face : faces) {
			vector < Point > pts;
			for (auto ind : face)
				pts.pb(verts[i][ind]);
			
			if (polygonArea2(pts) > 0) {//inner
				bool good = 0;
				for (int j = 1; j <= m; ++j) {
					if (!was[j] && inPolygon(pts, b[j])) {
						was[j] = 1;
						good = 1;
						inid[j] = sz(verts) - 1 - i;
					}
				}							
				
				if (good) {
					for (int j = 0; j < sz(pts); ++j) {
						int i1 = ID[mp(pts[j].x, pts[j].y)];
						int i2 = ID[mp(pts[(j + 1) % sz(pts)].x, pts[(j + 1) % sz(pts)].y)];
						assert(id[i1][i2] > 0);
						ans[id[i1][i2]] = 1;
					}
				}
				ifaces.pb(pts);
			} else
				ofaces.pb(pts);			
		}
		ifs.pb(ifaces);
		ofs.pb(ofaces);
		if (sz(ifaces) > 0)
			assert(sz(ofaces) == 1);		
	}

//	for (int i = 1; i <= e; ++i)
//		cout << ans[i];
//	cout << endl;
			
	reverse(all(ifs));
	reverse(all(ofs));
	
	for (int i2 = 0; i2 < sz(ofs); ++i2) {
		if (!sz(ofs[i2]))
			continue;

		auto pts2 = ofs[i2][0];
		
		bool found = 0, good = 0;
		for (int i1 = 0; i1 < i2 && !found; ++i1) {
			auto x = ifs[i1];
			for(auto pts: x) {
				bool ok = 0;			
				for(auto alo : pts2) 
					ok |= inPolygon(pts, alo);

				if (!ok) 
					continue;

				found = 1;
				for (int j = 1; j <= m; ++j) 
					if (!inPolygon(pts2, b[j]) && inPolygon(pts, b[j]) && inid[j] == i1) {
						good = 1;
						break;
					}							
				break;
			}
		}



		if (!found) {
			for (int j = 1; j <= m; ++j) 
				if (inid[j] == -1 && !inPolygon(pts2, b[j])) {
					good = 1;
					break;
				}							
		}

		if (good) {     
			for (int j = 0; j < sz(ofs[i2][0]); ++j) {
				int j1 = ID[mp(ofs[i2][0][j].x, ofs[i2][0][j].y)];
				int j2 = ID[mp(ofs[i2][0][(j + 1) % sz(ofs[i2][0])].x, ofs[i2][0][(j + 1) % sz(ofs[i2][0])].y)];
				assert(id[j1][j2] > 0);
				ans[id[j1][j2]] = 1;
			}
		}
	}
	/*
	for (int i1 = 0; i1 < sz(ifs); ++i1){
		auto x = ifs[i1];
		for(auto pts: x){
			for (int k = 1; k <= m; ++k) {
				if (inPolygon(pts, b[k]))
					in[i1][k] = 1;
			}
			
			for (int i2 = 0; i2 < sz(ofs); ++i2){
				auto y = ofs[i2];
				for(auto pts2: y){
					bool ok = 1;
					for(auto alo: pts2) ok &= inPolygon(pts, alo);
					if(!ok) continue;
					for(int i = 1; i <= m; i++){
						if(inPolygon(pts, b[i]))  {bad[i2][i] = 1;}
					}
				}
			}
		}
	}
	
	for (int i2 = 0; i2 < sz(ofs); ++i2){
		auto y = ofs[i2];
		if (!sz(y))
			continue;
		for(int i = 1; i <= m; i++){
			if(!in[i2][i] && !bad[i2][i]) {
				for (int j = 0; j < sz(ofs[i2][0]); ++j) {
					int j1 = ID[mp(ofs[i2][0][j].x, ofs[i2][0][j].y)];
					int j2 = ID[mp(ofs[i2][0][(j + 1) % sz(ofs[i2][0])].x, ofs[i2][0][(j + 1) % sz(ofs[i2][0])].y)];
					assert(id[j1][j2] > 0);
					ans[id[j1][j2]] = 1;
				}
				cerr << i2 << ' ' << i << ' ' << sz(ofs[i2][0]) << endl;
			}
		}
	}*/
	
	
	for (int i = 1; i <= e; ++i)
		cout << ans[i];
}
