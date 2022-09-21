#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int steps = 0;
    while (n) {
        int maxd = 0, temp = n;
        while (temp) {
            maxd = max(maxd, temp%10);
            temp /= 10;
        } 
        n -= maxd;
        steps++;
    }
    cout << steps << endl;
    return 0;
}