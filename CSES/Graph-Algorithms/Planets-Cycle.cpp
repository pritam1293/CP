#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<bool> vis;
vector<int> path_length, planets;
int steps = 0;
queue<int> q;

void dfs(int node) {
    q.push(node);
    if(vis[node]) {
        steps += path_length[node];
        return;
    }
    vis[node] = true;
    steps++;
    dfs(planets[node]);
} 

void solve() {
    int n;
    cin>>n;
    planets = vector<int> (n);
    for(int i=0;i<n;i++) {
        cin>>planets[i];
        planets[i]--;
    }
    vis = vector<bool>(n, false);
    path_length = vector<int>(n);
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            steps = 0;
            dfs(i);
            int dec = 1;
            while(!q.empty()) {
                if(q.front() == q.back()) dec = 0;
                path_length[q.front()] = steps;
                steps -= dec;
                q.pop();
            }
        }
    }
    for(auto& val : path_length) {
        cout<<val<<" ";
    }
}