#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int>demand(n), available(m);
    for (int i = 0; i < n; i++) {
        cin >> demand[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> available[i];
    }
    sort(demand.begin(), demand.end());
    sort(available.begin(), available.end());

    int i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (demand[i] <= available[j]+k && demand[i] >= available[j]-k) {
            ans++;
            i++;
            j++;
        }
        else if (demand[i] > available[j]+k) {
            j++;
        }
        else {
            i++;
        }
    }
    cout << ans << endl;
    
    return 0;
}