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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        bool flag = false;
        for(int j = i+1; j < n; j++) {
            if(vis[j]) continue;
            if((i+j) % 4 == 3) {
                vis[i] = true;
                vis[j] = true;
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout<<"Alice"<<endl;
            return;
        }
    }
    cout<<"Bob"<<endl;
}