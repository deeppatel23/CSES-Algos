#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int>nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<pair<int, int> >queries(m);
    for (int i = 0; i < m; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        queries[i] = make_pair(n1, n2);
    }

    vector<long long int>prefix(n, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = nums[i] + prefix[i-1];
    }
    for (int i = 0; i < m; i++) {
        long long int l = queries[i].first, r = queries[i].second;
        long long int ans = prefix[r-1] - (l-2 >= 0 ? prefix[l-2] : 0);
        cout << ans << endl;
    }
    return 0;
}