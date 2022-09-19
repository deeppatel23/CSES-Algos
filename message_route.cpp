#include<bits/stdc++.h>
using namespace std;

//using distance array and storing parent of each node in BFS
int main() {
    int n, m;
    cin >> n >> m;
    vector<int>adj[n+1];
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool>vis(n+1, false);
    queue<int>q;
    q.push(n);
    vis[n] = true;
    bool found = false;
    vector<int>parent(n+1);
    vector<int>dist(n+1, INT_MAX);
    dist[n] = 1;

    while (!q.empty() && !found) {
        int curr = q.front();
        q.pop();

        if (curr == 1) {
            found = true;
            break;
        }

        for (auto neg : adj[curr]) {
            if (!vis[neg]) {
                vis[neg] = true;
                parent[neg] = curr;
                dist[neg] = 1 + dist[curr];
                q.push(neg);
            }
        }
    }

    if (!found)
        cout << "IMPOSSIBLE\n";
    else {
        cout << dist[1] << endl;
        int x = 1;
        while (1) {
            cout << x << " ";
            if (x == n)
                break;
            x = parent[x];
        }
    }
    return 0;
}

//TLE
// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<int>adj[n+1];
//     for (int i = 0; i < m; i++) {
//         int x, y;
//         cin >> x >> y;
//         adj[x].push_back(y);
//         adj[y].push_back(x);
//     }

//     vector<bool>vis(n+1, false);
//     queue<pair<int, vector<int> > >q;
//     vector<int>init;
//     init.push_back(n);
//     q.push(make_pair(n, init));
//     vis[n] = true;
//     bool found = false;

//     while (!q.empty() && !found) {
//         int curr = q.front().first;
//         vector<int>v = q.front().second;
//         q.pop();

//         if (curr == 1) {
//             found = true;
//             cout << v.size() << endl;
//             reverse(v.begin(), v.end());
//             for (auto it : v)
//                 cout << it << " ";
//             break;
//         }

//         for (auto neg : adj[curr]) {
//             if (!vis[neg]) {
//                 vis[neg] = true;
//                 v.push_back(neg);
//                 q.push(make_pair(neg, v));
//                 v.pop_back();
//             }
//         }
//     }

//     if (!found)
//         cout << "IMPOSSIBLE\n";
//     return 0;
// }