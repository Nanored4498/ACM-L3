#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

vector<int> v[101];
int t[101];
int N;

bool f(int e, bool sens) {
	if(e > N) return true;
	if(sens) {
		for(int j = 1; j < 5; j++) {
			bool b = false;
			for(int vo : v[e]) {
				if(t[vo] == j) {
					b = true;
					break;
				}
			}
			if(b) continue;
			t[e] = j;
			if(f(e+1, false)) return true;
		}
	} else {
		for(int j = 4; j > 0; j--) {
			bool b = false;
			for(int vo : v[e]) {
				if(t[vo] == j) {
					b = true;
					break;
				}
			}
			if(b) continue;
			t[e] = j;
			if(f(e+1, true)) return true;
		}
	}
	t[e] = 0;
	return false;
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int a, b, i;
	char c;
	string s;

	while(cin >> N) {
		cin.ignore();
		while(true) {
			getline(cin, s);
			if(s.size() > 2) {
				istringstream ss(s);
				ss >> a >> c >> b;
				if(a < b) v[b].push_back(a);
				else v[a].push_back(b);
			} else break;
		}
		f(1, true);
		for(i = 1; i <= N; i++) {
			cout << i << " " << t[i] << "\n";
			v[i].clear();
			t[i] = 0;
		}
	}
	return 0;
}