#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long int>arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    long long int curr = 0, ans = 0, subsize = 0;
    unordered_map<long long int, long long int>m;
    for (int i = 0; i < n; i++) {
        int j = i;
        for (j = i; j < n; j++) {
            m[arr[j]]++;
            if (m.size() > k) {
                break;
            }
        }
        ans += j - i; //add contribution of ith element to answer
        m.clear();
        // cout << i << ":" << ans << " ";
    }
    cout << ans << endl;
    return 0;
}