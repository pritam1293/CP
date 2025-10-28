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
    string s, t;
    cin>>s>>t;
    map<char, int> mp;
    for(auto& c : s) mp[c]++;
    for(auto& c : t) {
        mp[c]--;
        if(mp[c] == -1) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}