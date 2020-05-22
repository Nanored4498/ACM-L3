#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, double> pid;
#define MAX_N 25
#define EPS 1e-9

struct Vec {
	double x, y, z;
	Vec(double x=0., double y=0., double z=0.): x(x), y(y), z(z) {}
	inline double norm2() { return x*x + y*y + z*z; }
	inline double norm() { return sqrt(norm2()); }
	inline Vec operator-(const Vec &b) { return Vec(x-b.x, y-b.y, z-b.z); }
	inline Vec operator+(const Vec &b) { return Vec(x+b.x, y+b.y, z+b.z); }
	inline Vec operator*=(double b) { x *= b; y *= b; z *= b; return *this; }
	inline Vec operator/=(double b) { x /= b; y /= b; z /= b; return *this; }
};

inline Vec cross(const Vec &a, const Vec &b) {
	return Vec(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

vector<Vec> ps;
vector<vector<pid>> path;
double mc[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q, s, t, c;
	double R, Rt = 6370.;
	double ph, th;
	int cas = 0;

	while(cin >> N) {
		// Read data
		++ cas;
		ps.resize(N);
		cin >> R;
		R /= Rt;
		double r = 2. * (1. - cos(R));
		double r2 = 2. * (1 - cos(2*R)) / 4.;
		for(int i = 0; i < N; ++i) {
			cin >> ph >> th;
			double cph = cos(ph*M_PI/180.), sph = sin(ph*M_PI/180.);
			double cth = cos(th*M_PI/180.), sth = sin(th*M_PI/180.);
			ps[i] = Vec(cth * cph, cth * sph, sth);
			mc[i] = 0;
		}

		// Generate intersections
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < i; ++j) {
				Vec v = ps[i] - ps[j];
				double v2 = v.norm2() / 4.;
				if(v2 > r2) continue;
				Vec mid = ps[i] + ps[j];
				Vec orth = cross(mid, v);;
				double x = (2 - r) / (2 * sqrt(1 - v2));
				double y = sqrt(1 - x*x);
				mid *= x / mid.norm();
				orth *= y / orth.norm();
				for(Vec a : {mid + orth, mid - orth}) {
					bool add = true;
					for(int k = 0; k < N; ++k) if(k != i && k != j && r-(a - ps[k]).norm2() > EPS) { add = false; break; } 
					if(add) ps.push_back(a);
					// if(add) cerr << cas << " " << i << " " << j << endl;
					// if(add) cerr << sqrt(r) << " " << (ps[i] - a).norm() << " " << (ps[j] - a).norm() << " " << a.norm() << endl;
				}
			}
		}
		path.resize(ps.size());

		// Find direct path
		for(int i = 0; i < ps.size(); ++i) {
			path[i].clear();
			for(int j = 0; j < ps.size(); ++j) if(j != i) {
				int k = i;
				while(true) {
					// if(path[j]-i)
				}
			}
		}

		cin >> Q;
		cout << "Case " << cas << ":\n";
		while(Q --> 0) {
			cin >> s >> t >> c;
			c /= Rt;
		}
	}

	return 0;
}