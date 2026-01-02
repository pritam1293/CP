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
    map<int, int> mp;
    for(int i = 0; i < 2*n; i++) {
        int x;
        cin>>x;
        mp[x]++;
    }
    int odd = 0, plus2 = 0, mul4 = 0;
    for(auto& [key, val] : mp) {
        if(val % 2 == 1) odd++;
        else if(val % 4) plus2++;
        else mul4++;
    }
    int ans = odd + 2*plus2 + 2*mul4;
    if(odd == 0 && mul4 % 2 == 1) ans -= 2;
    cout<<ans<<endl;
}