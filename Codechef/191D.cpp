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
    int n, q;
    cin>>n>>q;
    string s, t;
    cin>>s>>t;
    vector<int> pre(n);
    for(int i = 0, j = 0; i < n; i++) {
        if(s[i] == '1') {
            pre[j] = i-j;
            if(j != 0) pre[j] += pre[j-1];
            j++;
        }
    }
    sort(s.rbegin(), s.rend());
    reverse(t.begin(), t.end());
    vector<int> post(n);
    for(int i = 0, j = 0; i < n; i++) {
        if(t[i] == '1') {
            post[j] = i-j;
            if(j != 0) post[j] += post[j-1];
            j++;
        }
    }
    reverse(post.begin(),post.end());
    sort(t.begin(), t.end());
    int ans = LLONG_MAX;
    for(int i=0;i<n;i++) {
        if(s[i] == '1' && t[i] == '1') ans = min(ans, pre[i] + post[i]);
    }
    if(ans == LLONG_MAX) ans = -1;
    cout<<ans<<endl;
}