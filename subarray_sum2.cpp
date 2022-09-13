#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long int curr = 0, ans = 0;
    map<long long int, long long int>u;
    u[0] = 1;
    for (int i = 0; i < n; i++) {
        curr += arr[i];
        ans += u[curr - x];
        u[curr]++;
    }

    cout << ans << endl;

    return 0;
}