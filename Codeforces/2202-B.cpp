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


int rec(int i, int left, int right, string &s, string &t, int n) {
    if(i >= n) return 1;
    if(t[i] == '?') return rec(i+1, left+1, right, s, t, n) | rec(i+1, left, right-1, s, t, n);
    int ans = 0;
    if(t[i] == s[left]) ans |= rec(i+1, left+1, right, s, t, n);
    if(t[i] == s[right]) ans |= rec(i+1, left, right-1, s, t, n);
    return ans;
}

void solve() {
    int n;
    cin>>n;
    string t;
    cin>>t;
    string s;
    for(int i = 0; i < n; i++) {
        if(i % 2) s += 'b';
        else s += 'a';
    }
    if(rec(0, 0, n-1, s, t, n) == 1) {
        cout<<"YES"<<endl;
    } 
    else {
        cout<<"NO"<<endl;
    }
}