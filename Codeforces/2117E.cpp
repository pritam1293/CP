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
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> b(n);
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    if(a[n-1] == b[n-1]) {
        cout<<n<<endl;
        return;
    }
    vector<bool> vis(n+1, false);
    int ans = 0;
    for(int i=n-2;i>=0;i--) {
        if(a[i] == b[i] || a[i] == a[i+1] || b[i] == b[i+1] || vis[a[i]] || vis[b[i]]) {
            ans = i+1;
            break;
        }
        vis[a[i+1]] = true;
        vis[b[i+1]] = true;
    } 
    cout<<ans<<endl;
}