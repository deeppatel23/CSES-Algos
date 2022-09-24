#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

vector<int>tree[200001];
vector<int>ans;

void solve(int src) {
    int subords = 0;
    for (auto child : tree[src]) {
            solve(child);
            subords += (1 + ans[child]);
    }
    ans[src] = subords;
}

int main() {
    int n;
    cin >> n;
    ans.resize(n+1, 0);
    
    for (int i = 2; i <= n; i++) {
        int boss; 
        cin >> boss;
        tree[boss].push_back(i);
    }

    solve(1);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    
    cout << endl;
    return 0;
}