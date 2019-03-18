#include <iostream>

using namespace std;

int main() {
	int a[5];
	int x = 0;
	bool answer;
 	while (cin >> a[0]) {
		answer = true;
	for (int i = 1; i < 5; i++)
		cin >> a[i];
	for (int i = 0; i < 5; i++) {
		cin >> x;
		if (x == a[i])
			answer = false;
	}
	if (answer)
		cout << "Y" << endl;
	else
		cout << "N" << endl;
	}
	return 0;
}
