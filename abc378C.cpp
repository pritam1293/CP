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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    map<int,int> mp;
    vector<int> b(n);
    for(int i=0;i<n;i++) {
        if(mp.find(a[i]) == mp.end()) {
            b[i] = -1;
        }
        else {
            b[i] = mp[a[i]];
        }
        mp[a[i]] = i+1;
    }
    for(int i=0;i<n;i++) {
        cout<<b[i]<<" ";
    }
}
