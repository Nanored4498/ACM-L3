#include<iostream>
#include<string>

using namespace std;

int main(){
	int N, B, H, W;
	int p, n;
	bool b;
	while(cin >> N >> B >> H >> W) {
		int res = 500001;
		for(int i = 0; i < H; i++) {
			cin >> p;
			b = p*N <= B && res > p*N;
			for(int j = 0; j <  W; j++) {
				cin >> n;	
				if(b && n >= N) {
					res = p*N;
					b = false;
				}
			}
		}
		if(res == 500001) cout << "stay home\n";
		else cout << res << endl;
	}
}
