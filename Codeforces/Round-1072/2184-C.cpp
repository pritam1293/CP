#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, k;
    cin>>n>>k;
    if(n == k) {
        cout<<0<<endl;
        return;
    }
    queue<pair<int, int>> q;
    q.push({n, 0});
    set<int> vis;
    vis.insert(n);
    while(!q.empty()) {
        int p = q.front().first, t = q.front().second;
        q.pop();

        int p1 = p / 2;
        int p2 = p - p1;
        if(p1 == k || p2 == k) {
            cout<<t+1<<endl;
            return;
        }
        if(p1 > k && vis.find(p1) == vis.end()) {
            vis.insert(p1);
            q.push({p1, t+1});
        }
        if(p2 > k && vis.find(p2) == vis.end()) {
            vis.insert(p2);
            q.push({p2, t+1});
        }
    }
    cout<<-1<<endl;
}