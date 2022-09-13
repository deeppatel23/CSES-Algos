#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    queue<int>q;
    int curr = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        curr += arr[i];
        q.push(arr[i]);

        if (curr == x) {
            ans++;
        }
        else if (curr > x) {
            while (curr > x && !q.empty()) {
                curr -= q.front();
                q.pop();
            }
            if (curr == x) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}