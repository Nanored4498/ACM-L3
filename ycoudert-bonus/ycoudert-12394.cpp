#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int rev[1000][5];
	char ins[1000][11];
	int nr[1000]; //nombre de review
	int K, N;
	int i, res;
	short j, k;
	bool b = false;
	while(cin >> K >> N) {
		if(N == 0 && K == 0)
			break;
		for(i = 0; i < N; i++) {
			cin >> ins[i];
			for(j = 0; j < K; j++)
				cin >> rev[i][j];
		}
		for(i = 0; i < N; i++) {
			for(j = 0; j < K; j++) {
				/* Pas le droit d'être corrigé deux fois par la même personne */
				for(k = 0; k < j; k++) {
					if(rev[i][k] == rev[i][j]) {
						nr[rev[i][k]-1] = 6;
						break;
					}
				}
				/* On fait attention que le papier corrigé ne fait pas parti de la même institution */
				if(strcmp(ins[i], ins[rev[i][j]-1]) == 0) nr[rev[i][j]-1] = 6;
				else nr[rev[i][j]-1] ++;
			}
		}
		res = 0;
		for(i = 0; i < N; i++) {
			if(nr[i] != K) res ++;
			nr[i] = 0;
		}
		if(res == 0) cout << "NO PROBLEMS FOUND\n";
		else if(res == 1) cout << "1 PROBLEM FOUND\n";
		else cout << res << " PROBLEMS FOUND\n";
	}
}