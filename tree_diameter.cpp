#include<bits/stdc++.h>
using namespace std;

int d = 0, bestNode = 0;
void solve(vector<int>adj[], int node, int par, int depth) {
    for (auto neg : adj[node]) {
        if (neg != par) {
            solve(adj, neg, node, depth+1);
        }
    }
    if (d < depth) {
        d = depth;
        bestNode = node;
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int>adj[n+1];

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(adj, 1, 0, 0);
    solve(adj, bestNode, 0, 0);
    cout << d << endl;

    return 0;
}