#include<iostream>
#include<string>

using namespace std;

int main(){
    cout.tie(NULL);
    ios::sync_with_stdio(false);
	long long calls[10000][2];
	int N, M;
	long long s, d;
	int i, j, n;
	while(cin >> N >> M) {
		if(N == 0 && M == 0)
			break;
		for(i = 0; i < N; i++) {
			cin.ignore(10, ' ');
			cin.ignore(10, ' ');
			cin >> calls[i][0] >> calls[i][1];
			calls[i][1] += calls[i][0];
		}
		for(i = 0; i < M; i++) {
			n = 0;
			cin >> s >> d;
			for(j = 0; j < N; j++)
				if(s < calls[j][1] && s+d > calls[j][0])
					n ++;
			cout << n << endl;
		}
	}
}