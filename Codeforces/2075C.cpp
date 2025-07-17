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
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    vector<int> freq(n+1);
    for(int i=0;i<m;i++) {
        cin>>a[i];
        freq[a[i]]++;
    }
    
    vector<int> cnt(n+2);
    for(int i=n;i>=1;i--) {
        cnt[i] = freq[i] + cnt[i+1];
    }

    long long ans = 0;
    for(int i=1;i<n;i++) {
        long long left = cnt[i];
        long long right = cnt[n-i];

        long long same = cnt[max(i, n-i)];

        ans += left * right - same;
    }
    cout<<ans<<endl;
}