#include<bits/stdc++.h>
using namespace std;

// int main() {
//     int n, m;
//     cin >> n >> m;
//     vector<vector<char>>grid(n, vector<char>(m));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> grid[i][j];
//         }
//     }

//     queue<pair<int, int>>mons;
//     queue<pair<pair<int, int>, string>>you;
//     vector<vector<bool>>vism(n, vector<bool>(m, false));
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (grid[i][j] == 'M') {
//                 mons.push({i, j});
//                 vism[i][j] = true;
//             }
//             else if (grid[i][j] == 'A') {
//                 you.push({{i, j}, ""});
//             }
//         }
//     }

//     while (!you.empty()) {
//         int sm = mons.size();
//         while (sm--) {
//             auto currm = mons.front(); mons.pop();
//             int currx = currm.first, curry = currm.second;
//             if (currx-1 >= 0 && grid[currx-1][curry] != '#' && !vism[currx-1][curry]) {
//                 grid[currx-1][curry] = 'M';
//                 mons.push({currx-1, curry});
//                 vism[currx-1][curry] = true;
//             }
//             if (currx+1 < n && grid[currx+1][curry] != '#' && !vism[currx+1][curry]) {
//                 grid[currx+1][curry] = 'M';
//                 mons.push({currx+1, curry});
//                 vism[currx+1][curry] = true;
//             }
//             if (curry-1 >= 0 && grid[currx][curry-1] != '#' && !vism[currx][curry-1]) {
//                 grid[currx][curry-1] = 'M';
//                 mons.push({currx, curry-1});
//                 vism[currx][curry-1] = true;
//             }
//             if (curry+1 < m && grid[currx][curry+1] != '#' && !vism[currx][curry+1]) {
//                 grid[currx][curry+1] = 'M';
//                 mons.push({currx, curry+1});
//                 vism[currx][curry+1] = true;
//             }
//         }
//         int sy = you.size();
//         while (sy--) {
//             auto curr = you.front(); you.pop();
//             int currx = curr.first.first, curry = curr.first.second;
//             string path = curr.second;
//             // cout << "P: "<< path << endl;
//             if (currx == 0 || currx == n-1 || curry == 0 || curry == m-1) {
//                 cout << "YES" << '\n' << path.size() << '\n' << path << endl;
//                 return 0;
//             }
//             if (currx-1 >= 0 && grid[currx-1][curry] == '.') {
//                 you.push({{currx-1, curry}, path + "U"});
//             }
//             if (currx+1 < n && grid[currx+1][curry] == '.') {
//                 you.push({{currx+1, curry}, path + "D"});
//             }
//             if (curry-1 >= 0 && grid[currx][curry-1] == '.') {
//                 you.push({{currx, curry-1}, path + "L"});
//             }
//             if (curry+1 < m && grid[currx][curry+1] == '.') {
//                 you.push({{currx, curry+1}, path + "R"});
//             }
//         }
//     }
//     cout << "NO\n";
//     return 0;
// }


//https://www.youtube.com/watch?v=bWAbE2ZlqAE

#define pi (3.141592653589)
#define mod 1000000007
//#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
vector<string> v;
int n, m;
 
 
int dist[1001][1001]; //steps needed by monster to reach i,j
int d[1001][1001]; //steps for person
int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 };
 
int main() {
    fast
    int t = 1;
    // cin >> t;
    while(t--) {
        rep(i, 1001)rep(j, 1001)dist[i][j]=-1;
        cin>>n>>m;
        for(int i = 0; i < n; i++){
        	string x;cin>>x;
            v.pb(x);
        }
        int x,y,c1,c2;
        queue<vector<int>>q;
        rep(i, n){
        	rep(j, m){
        		if(v[i][j]=='M')q.push({i, j, 0});
        		if(v[i][j]=='A')c1=i, c2=j;
			}
		}
		x=c1, y=c2;
        while(!q.empty()) {
            auto curr= q.front();
            q.pop();
            int x=curr[0], y=curr[1], steps=curr[2];
            if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y]=='#' || dist[x][y]!=-1)continue;
            dist[x][y]=steps;
            rep(i, 4){
                int cx=x+dx[i], cy=y+dy[i];
                q.push({ cx, cy, steps+1});
            }
        }
        string ans;
        while(!q.empty())   q.pop();
        q.push({ x, y, 0, 0 });
        rep(i, 1001)rep(j, 1001)d[i][j]=-1;
        bool c = false;
        int p[n + 1][m + 1];
        memset(p, 0, sizeof(p));
        while(!q.empty()) {
            auto curr=q.front();
            q.pop();
            int x =curr[0], y =curr[1], steps =curr[2], dir =curr[3];
            if(x < 0 || x > n - 1 || y < 0 || y > m - 1 || v[x][y] == '#' || d[x][y] != -1 || (dist[x][y] >= 0 and dist[x][y] <= steps))
                continue;
            if(x == n - 1 || y == m - 1 || x == 0 || y == 0) {
                p[x][y] = dir;
                while(x != c1 or y != c2) {
                    if(p[x][y] == 0)    ans += 'L', y++;// path is from (x, y) to (x, y-1) so ans+='L' and (0=> {0, -1}) thats why y++.
                    else if(p[x][y] == 1) ans += 'R', y--;
                    else if(p[x][y] == 2)  ans += 'U', x++;
                    else    ans += 'D', x--;	
                }
                reverse(ans.begin(), ans.end());
                c=true;
                break;
            }
            d[x][y] = steps;
            p[x][y] = dir;
            rep(i, 4){
                int cx=x+dx[i], cy=y+dy[i];
                q.push({ cx, cy, steps + 1, i });
            }
        }
        if(c){
            cout<<"YES"<<endl<<ans.size()<<endl<<ans;
        }
        else
            cout << "NO"<<endl;
    }
	return 0;
}