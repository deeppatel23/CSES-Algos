#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long int>arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    long long int curr = 0, ans = 0;
    unordered_map<long long int, long long int>m;
    m[0]++;
    for (int i = 0; i < n; i++) {
        curr += arr[i];
        long long int t  = (curr % n + n) % n; //for negative sums
        ans += m[t]; //if reminder repeats then there is sum: multiple of n
        m[t]++;
    }
    cout << ans << endl;
    return 0;
}