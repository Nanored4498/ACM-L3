#include<iostream>
#include<string>

using namespace std;

int main(){
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    long long a, b;
    while(cin >> a >> b)
        cout << ((a > b) ? a-b : b-a) << endl;
}
