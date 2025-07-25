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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int l = -1, r = -1;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            l = i;
            break;
        }
    }
    for(int i = n-2; i >= l; i--) {
        if(s[i+1] != s[i]) {
            r = i;
            break;
        }
    }
    if(l == -1 || r == -1) {
        cout<<n<<endl;
        return;
    }
    int ans = l + 1 + n - r;
    if(s[l] != s[r]) ans--;
    else ans -= 2;
    cout<<ans<<endl;
}