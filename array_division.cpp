#include<bits/stdc++.h>
using namespace std;

bool ispossible(vector<int>v, long long int sum, int k) {
    long long int t = 1, curr = 0;
    for (auto n : v) {
        curr += n;
        if (curr > sum) {
            t++;
            curr = n;
        }
        if (n > sum)
            return false;
    }
    if (t > k)
        return false;
    return true;
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int>arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long int maxsum = 0;
    for (auto n : arr) {
        maxsum += n;
    }

    long long int l = 0, h = maxsum, ans = -1;
    while(l <= h) {
        long long int mid = l + ((h-l)/2);
        if (ispossible(arr, mid, x)) {
            ans = mid;
            h = mid-1;
        }
        else {
            l  = mid+1;
        }
    }
    cout << ans << endl;

    return 0;
}