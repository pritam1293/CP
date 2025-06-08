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
    string s;
    cin>>s;
    int idx = -1;
    for(int i=1;i<n;i++) {
        if(s[i] < s[i-1]) {
            idx = i-1;
            break;
        }
    }
    if(idx == -1) {
        cout<<s<<endl;
        return;
    }
    bool flag = false;
    for(int i=0;i<idx;i++) {
        cout<<s[i];
    }
    for(int i = idx+1; i < n; i++) {
        if(s[i] > s[idx] && !flag) {
            cout<<s[idx]<<s[i];
            flag = true;
        }
        else {
            cout<<s[i];
        }
    }
    if(!flag) {
        cout<<s[idx];
    }
    cout<<endl;
}