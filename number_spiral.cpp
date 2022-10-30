#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll r, c;
        cin >> r >> c;
        if (c > r) {
            ll ans;
            if (c % 2 != 0)
                ans = (c*c) - r + 1;
            else
                ans = ((c-1)*(c-1)) + r;
            cout << ans << endl;
        }
        else {
            ll ans;
            if (r % 2 == 0)
                ans = (r*r) - c + 1;
            else
                ans = ((r-1)*(r-1)) + c;
            cout << ans << endl;
        }
    }
    return 0;
}