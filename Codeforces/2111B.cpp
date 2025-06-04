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
    int n,m;
    cin>>n>>m;
    vector<int> fib(n);
    fib[0] = 1;
    fib[1] = 2;
    for(int i=2;i<n;i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    // for(auto it : fib) {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    string s;
    for(int i=0;i<m;i++) {
        int w, l, h;
        cin>>w>>l>>h;
        int mx = max({w, l, h});
        int mn = min({w, l, h});
        int min_req = fib.back();
        int max_req = fib[n-1]+fib[n-2];
        if(min_req <= mn && max_req <= mx) s += "1";
        else s += "0";
    }
    cout<<s<<endl;
}