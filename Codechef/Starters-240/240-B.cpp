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
    string a, b;
    cin>>a>>b;
    vector<int> pa, pb;
    for(int i = 0; i < n; i++) {
        if(a[i] == '1') pa.push_back(i);
        if(b[i] == '1') pb.push_back(i);
    }
    if((int)pa.size() != (int)pb.size()) {
        cout<<"-1"<<endl;
        return;
    }
    int cnt = 0;
    for(int i = 0; i < (int)pa.size(); i++) {
        if(pa[i] != pb[i]) cnt++;
    }
    cout<<cnt<<endl;
}