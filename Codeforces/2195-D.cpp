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
    vector<int> a(n);
    for(auto& e : a) {
        cin>>e;
    }
    int sum = (a[0] + a[n-1]) / (n-1);
    int s = 0;
    for(int i = 1; i < n; i++) {
        int num = (a[i] + sum - a[i-1]) / 2 - s;
        cout<<num<<" ";
        s += num;
    }
    cout<<sum - s<<endl;
}