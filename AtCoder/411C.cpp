#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, q;
    cin>>n>>q;
    vector<bool> vis(n+2, false);
    int cnt = 0;
    while(q--) {
        int x;
        cin>>x;
        if(!vis[x]) {
            vis[x] = true;
            bool left = vis[x-1];
            bool right = vis[x+1];

            if(!left && !right) cnt++;
            else if(left && right) cnt--;
        }
        else {
            vis[x] = false;
            bool left = vis[x-1];
            bool right = vis[x+1];
            if(!left && !right) cnt--;
            else if(left && right) cnt++;
        }
        cout<<cnt<<endl;
    }
}