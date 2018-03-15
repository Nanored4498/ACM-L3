#include<iostream>

using namespace std;

int main(){
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    char c;
	bool b = true;
	cin >> noskipws;
    while(cin >> c)
    	if(c == '"') {
			cout << (b ? "``" : "''");
			b = !b;
		} else cout << c;
	return 0;
}