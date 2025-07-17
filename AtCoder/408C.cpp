#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<pair<int,int>> a(m);
    vector<int> diff(n+1);
    for(int i=0;i<m;i++) {
        int l, r;
        cin>>l>>r;
        a[i] = {l, r};
        diff[l]++;
        diff[r+1]--;
    }
    vector<int> covered(n+1);
    int ans = m;
    for(int i=1;i<=n;i++) {
        covered[i] = covered[i-1] + diff[i];
        // cout<<covered[i]<<" ";
        ans = min(ans, covered[i]);
    }
    cout<<ans<<endl;
}