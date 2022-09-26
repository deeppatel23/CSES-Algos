#include<bits/stdc++.h>
using namespace std;

int d = 0, endNode1 = 0, endNode2 = 0;
vector<int>dist;
void solve(vector<int>adj[], int node, int par, int depth) {
    dist[node] = max(dist[node], depth);
    for (auto neighbour : adj[node]) {
        if (neighbour != par) {
            solve(adj, neighbour, node, depth+1);
        }
    }
    if (d < depth) {
        d = depth;
        endNode1 = node;
    }
    return;
}

int main() {
    int n;
    cin >> n;
    vector<int>adj[n+1];
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dist = vector<int>(n+1, 0);
    solve(adj, 1, 0, 0);
    solve(adj, endNode1, 0, 0);
    solve(adj, endNode1, 0, 0); //endNode1 will have value of endNode2
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    return 0;
}