#include <iostream>
#include <map>

using namespace std;

int main() {
	string line;
	map<string, string> dico;
	while(true) {
		getline(cin, line);
		if(line.empty()) break;
		int i = line.find(' ');
		string eng = line.substr(0, i);
		string foreign = line.substr(i+1, line.size()-i-1);
		dico[foreign] = eng;
	}

	while(cin >> line) {
		if(dico.count(line) > 0) cout << dico[line] << "\n";
		else cout << "eh\n";
	}

	return 0;
}