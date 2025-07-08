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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int one = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') one++;
    }
    if(one <= k) {
        cout<<"Alice"<<endl;
        return;
    }
    if(2*k <= n) {
        cout<<"Bob"<<endl;
        return;
    }
    int zero = 0;
    for(int i = 0;i < n; i++) {
        if(s[i] == '0') zero++;
        else zero = 0;
        if(zero >= k) {
            cout<<"Bob"<<endl;
            return;
        }
    }
    cout<<"Alice"<<endl;
}