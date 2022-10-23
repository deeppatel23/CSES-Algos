#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int>u;
    for (auto n : nums) {
        u[n]++;
    }
    cout << u.size() << endl;
    return 0;
}