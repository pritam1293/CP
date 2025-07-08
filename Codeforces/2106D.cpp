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
    int n, m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];
    vector<int> prefix(m), suffix(m);
    int j = 0;
    for(int i = 0; i < m; i++) {
        while(j < n && a[j] < b[i]) j++;
        prefix[i] = j++;
    }
    if(prefix[m-1] < n) {
        cout<<0<<endl;
        return;
    }
    j = n-1;
    for(int i = m-1; i >= 0; i--) {
        while(j >= 0 && a[j] < b[i]) j--;
        suffix[i] = j--;
    }
    int inf = INT_MAX;
    int ans = inf;

    for(int i = 0; i < m; i++) {
        int left = (i == 0 ? -1 : prefix[i-1]);
        int right = (i == m-1 ? n : suffix[i+1]);
        if(left < right) ans = min(ans, b[i]);
    }
    cout<<(ans == inf ? -1 : ans)<<endl;
}