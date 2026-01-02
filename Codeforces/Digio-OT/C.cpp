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
    if(n == 1) {
        cout<<"1"<<endl;
        return;
    }
    if(n == 2) {
        cout<<"1 2"<<endl;
        return;
    }
    int c = 4;
    vector<int> a(n);
    a[0] = 2;
    a[n/2] = 1;
    a[n-1] = 3;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) a[i] = c++;
    }
    for(auto& e : a) {
        cout<<e<<" ";
    }
    cout<<endl;
}