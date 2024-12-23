#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<int> v(5);
    v[a]++;
    v[b]++;
    v[c]++;
    v[d]++;
    int ans = 0;
    for(auto it : v) {
    	ans += it/2;
    }
    cout<<ans;
}
