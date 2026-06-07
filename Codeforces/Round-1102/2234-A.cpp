#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    if (!freopen("../../input.txt", "r", stdin)) {
        cerr << "Failed to open input.txt\n";
    }
    if (!freopen("../../output.txt", "w", stdout)) {
        cerr << "Failed to open output.txt\n";
    }
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}    

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto& e : a) {
        cin>>e;
    }
    sort(a.rbegin(), a.rend());
    for(int i = 2; i < n; i++) {
        if(a[i] != a[i-2] % a[i-1]) {
            cout<<"-1"<<endl;
            return;
        }
    }
    cout<<a[0]<<" "<<a[1]<<endl;
}