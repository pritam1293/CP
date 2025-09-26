#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<bool> vis(n+1, false);
    int c = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        vis[x] = true;
        if(x == k) c++;
    }
    int ans = 0;
    for(int i = 0; i < k; i++) {
        if(!vis[i]) {
            if(c) {
                c--;
                ans++;
                vis[i] = true;
            }
            else break;
        }
        if(c == 0) break;
    }
    for(int i = 0; i < k; i++) {
        if(!vis[i]) ans++;
    }
    cout<<ans + c<<endl;
}