#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
  	map<string, int> m;
	string s;
	int j, k, n;
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		j = 0;
		while(s[j]==' ') j++;
		k = 1;
		while(s[j+k]!=' ') k++;
		m[s.substr(j, k)] += 1;
	}
	for(auto& p : m)
		cout << p.first << " " << p.second << endl;
}
