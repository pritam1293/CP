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
    int n;
    cin>>n;
    if(n < 3) {
        cout<<"-1"<<endl;
        return;
    }
    for(int i = 0; i < n; i++) {
        cout<<"1 ";
    }
    cout<<endl;
    for(int i = 0; i < n-2; i++) {
        cout<<"0 ";
    }
    cout<<"1 1"<<endl;
    for(int i = 0; i < n-2; i++) {
        cout<<"0 ";
    }
    cout<<"1 1"<<endl;
    for(int i = 3; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            cout<<"0 ";
        }
        cout<<"1"<<endl;
    }
}