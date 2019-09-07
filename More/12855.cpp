#include <iostream>
#include <map>

using namespace std;

long long A, B;
map<string, int> m;

int main() {
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	
	string s;
	while(cin >> A >> B >> s) {
		m.clear();
		int nb = 0;
		for(char c : s) if(c == 'B') nb ++;
		int des = nb-1;
		long long res = 0;
		for(int i = nb; i < s.size(); i++) {
			if(s[i] == 'W') continue;
			while(s[des] == 'B') des --;
			res += min(A, (i-des) * (A - B));
			s[des] = 'B';
		}
		cout << res << "\n";
	}
	return 0;
}