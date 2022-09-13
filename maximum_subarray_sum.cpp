#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    long long int curr = 0, ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        curr += arr[i];
        ans = max(ans, curr);
        if (curr < 0) {
            curr = 0;
        }
    }
    cout << ans << endl;
    return 0;
}