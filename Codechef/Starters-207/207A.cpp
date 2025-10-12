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
    string s;
    cin>>s;
    int left = n+1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            left = i;
            break;
        }
    }
    int right = -1;
    for(int i = n-1; i >= 0; i--) {
        if(s[i] == '1') {
            right = i;
            break;
        }
    }
    if(left > right) {
        cout<<"0"<<endl;
        return;
    }
    int cnt = 0;
    for(int i = left; i <= right; i++) {
        if(s[i] == '0') cnt++;
    }
    cout<<cnt<<endl;
}