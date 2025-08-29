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
    int n, k;
    cin>>n>>k;
    multiset<int> s, t;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        x %= k;
        s.insert(x);
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        x %= k;
        auto it = s.find(x);
        if(it != s.end()) s.erase(it);
        else t.insert(x);
    }
    for(auto& e : s) {
        int need = k - e;
        auto it = t.find(need);
        if(it == t.end()) {
            cout<<"NO"<<endl;
            return;
        }
        else t.erase(it);
    }
    cout<<"YES"<<endl;
}