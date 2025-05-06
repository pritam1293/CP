#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<int> countFriends(vector<int> &u, vector<int> &v, int n) {
    vector<vector<int>> graph(n+1);
    for(int i=0;i<u.size();i++) {
        graph[u[i]].push_back(v[i]);
        graph[v[i]].push_back(u[i]);
    }

    vector<>
}

void solve() {
    
}
