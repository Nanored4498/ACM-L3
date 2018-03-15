#include<iostream>

using namespace std;

bool prime[32] = {false, false, true, true, false, true, false, true, false, false, false, true, false, true, false, false,
        false, true, false, true, false, false, false, true, false, false, false, false, false, true, false, true};

void print(short *t, short n) {
    cout << t[0];
    for(short i = 1; i < n; i++) cout << " " << t[i];
    cout << endl;
}

void f(short n, short *t, short i, short *t2) {
    if(i == n) {
        if(prime[t2[n-1]+1]) print(t2, n);
    } else {
        short j = i, temp;
        t2[i] = t[j];
        if(prime[t2[i]+t2[i-1]])
            f(n, t, i+1, t2);
        for(j ++; j < n; j++) {
            temp = t2[i];
            t2[i] = t[j];
            t[j] = temp;
            if(prime[t2[i]+t2[i-1]])
                f(n, t, i+1, t2);
        }
        for(j = i+1; j < n-1; j++)
            t[j] = t[j+1];
        t[n-1] = t2[i];
    }
}

int main() {
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    short c = 1, n;
    short t[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16}, t2[16];
    t2[0] = 1;
    while(cin >> n) {
        if(c > 1) cout << endl;
        cout << "Case " << c << ":\n";
        if(n == 1 || n%2 == 0) f(n, t, 1, t2);
        c ++;
    }

	return 0;
}