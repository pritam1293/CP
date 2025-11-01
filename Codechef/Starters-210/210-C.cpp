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
    string s;
    cin>>s;
    int bal = 0, mn = 0;
    for(auto& c : s) {
        if(c == '0') bal++;
        else bal--;
        mn = min(mn, bal);
    }
    if(bal == mn) {
        if(mn == 0) {
            cout<<0<<endl;
        }
        else {
            cout<<1<<endl;
        }
        return;
    }
    bal = 0; mn = 0;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '1') bal++;
        else bal--;
        mn = min(bal, mn);
    }
    if(bal == mn) {
        if(mn == 0) {
            cout<<0<<endl;
        }
        else {
            cout<<1<<endl;
        }
        return;
    }
    cout<<2<<endl;
}