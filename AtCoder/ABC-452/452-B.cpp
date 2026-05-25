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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        cout<<"#";
    }
    cout<<endl;
    for(int i = 1; i < n-1; i++) {
        cout<<"#";
        for(int j = 1; j < m-1; j++) {
            cout<<".";
        }
        cout<<"#"<<endl;
    }

    for(int i = 0; i < m; i++) {
        cout<<"#";
    }
}