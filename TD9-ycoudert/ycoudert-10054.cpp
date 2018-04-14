#include <iostream>
#include <vector>

using namespace std;

int m[51][51];
int c[51], mi[51];

void euler(int i) {
	if(c[i] == 0) return;
	vector<int> v;
	int j = i;
	do {
		int k = mi[j];
		while(m[j][k] == 0) k++;
		m[j][k] = --m[k][j];
		c[j] --;
		c[k] --;
		mi[j] = k;
		j = k;
		v.push_back(j);
	} while(j != i);
	euler(i);
	for(int j : v) {
		cout << i << " " << j << "\n";
		euler(j);
		i = j;
	}
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

	int T, N;
	int a, b, i, j, l;
	cin >> T;

	for(int t = 1; t <= T; t++) {
		if(t > 1) cout << "\n";
		cout << "Case #" << t << "\n";
		cin >> N;
		for(i = 1; i < 51; i++) {
			c[i] = 0, mi[i] = 1;
			for(j = 1; j < 51; j++) m[i][j] = 0;
		}
		for(i = 0; i < N; i++) {
			cin >> a >> b;
			c[a] ++;
			c[b] ++;
			m[a][b] = ++m[b][a];
		}
		bool bo = false;
		for(i = 1; i < 51; i++) {
			if(c[i] > 0) {
				l = i;
				if(c[i] % 2 == 1){
					bo = true;
					break;
				}
			}
		}
		if(bo) cout << "some beads may be lost\n";
		else euler(l);
	}
	return 0;
}