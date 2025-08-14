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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    if(k >= 3) {
        cout<<"0"<<endl;
    }   
    else {
        while(k--) {
            int diff = 1e18;
            for(int i = 0; i < (int)a.size(); i++) {
                for(int j = i+1; j < (int)a.size(); j++) {
                    diff = min(diff, abs(a[i] - a[j]));
                }
            }
            a.push_back(diff);
        }
        int mn = 1e18;
        for(auto& e : a) mn = min(mn, e);
        cout<<mn<<endl;
    }
}