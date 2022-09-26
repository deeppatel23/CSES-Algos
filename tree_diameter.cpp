#include<bits/stdc++.h>
using namespace std;

int d = 0, endNode1 = 0;
void solve(vector<int>adj[], int node, int par, int depth) {
    for (auto neg : adj[node]) {
        if (neg != par) {
            solve(adj, neg, node, depth+1);
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

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve(adj, 1, 0, 0); //to get maximum distant node (endNode1) from any arbitaty node 1, so endNode1 is 1st end point of diameter
    solve(adj, endNode1, 0, 0); //now get maximum distant node from endNode1, to get second endPoint of diameter
    cout << d << endl;

    return 0;
}