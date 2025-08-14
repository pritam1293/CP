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
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>b[i];
    }
    vector<int> cnt(n+1);
    vector<bool> e(n+1, false);
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) e[a[i]] = true;
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    int i = 0;
    while(i <= n && cnt[i]) i++;
    bool f = false;
    for(int j = 0; j < i; j++) {
        if(cnt[j] && !e[j]) {
            if(!f) f = true;
            else {
                i = j;
                break;
            }
        }
    }
    cout<<i<<endl;
}