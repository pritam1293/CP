#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
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
    vector<int> a;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(a.empty() || a.back() != x) a.push_back(x);
    }
    n = a.size();
    int ans = 0;
    if(n == 1) {
        cout<<1<<endl;
        return;
    }
    for(int i=0;i<n;i++) {
        if(i > 0 && a[i] > a[i-1] && i < n-1 && a[i] > a[i+1]) ans++;
        else if(i == 0 && a[i] > a[i+1]) ans++;
        else if(i == n-1 && a[i] > a[i-1]) ans++; 
    }
    cout<<ans<<endl;
}