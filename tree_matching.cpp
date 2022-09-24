#include<bits/stdc++.h>
using namespace std;

int solve(vector<pair<int, int> >&edges, vector<bool>used, int idx) {
    if (idx == edges.size()) {
        return 0;
    }
    int x = edges[idx].first, y = edges[idx].second;
    if (used[x] || used[y]) {
        return 0;
    } 
    int c1 = 0, c2 = 0;
    used[x] = true;
    used[y] = true;
    c2 = 1 + solve(edges, used, idx+1);
    used[x] = false;
    used[y] = false;
    c1 = solve(edges, used, idx+1);
    return max(c1, c2);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int> >edges;
    vector<bool>used(n+1, false);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back(make_pair(x, y));
        // edges.push_back(make_pair(y, x));
    }

    cout << solve(edges, used, 0);

    cout << endl;
    return 0;
}