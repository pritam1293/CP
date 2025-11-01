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
    int r, x, d, n;
    cin>>r>>x>>d>>n;
    string s;
    cin>>s;
    // cout<<r<<" "<<x<<" "<<d<<" "<<n<<endl;
    // cout<<s<<endl;
    // cout<<endl;
    int cnt = 0;
    for(auto& c : s) {
        if(c == '1') {
            r = max(r-d, 0ll);
            cnt++;
        }
        else if(c == '2' && r < x) {
            r = max(r-d, 0ll);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}