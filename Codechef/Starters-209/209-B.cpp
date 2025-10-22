#include<bits/stdc++.h>
using namespace std;
// #define int long long
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
    string s;
    cin>>s;
    vector<int> idx;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            idx.push_back(i);
        }
    }
    bool f = true;
    if(idx.size() == 2) {
        if(idx[1] - idx[0] <= 1) f = false;
    }
    else if(idx.size() == 3) {
        if(idx[2] - idx[0] == 2) f = false;
    }
    if(f) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}
