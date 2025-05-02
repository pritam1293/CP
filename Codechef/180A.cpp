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
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    if(n == 1) {
        cout<<a[0]<<endl;
        return;
    }
    int maxm = 0;
    int ans = 0;
    for(int i=0;i<n;i++) {
        if(i % 2 == 0) {
            ans = max(ans, a[i]);
        }
        maxm = max(maxm, a[i]);
    }
    ans += n/2;
    vector<int> idx;
    for(int i=0;i<n;i++) {
        if(a[i] == maxm && i % 2 == 0) {
            cout<<ans<<endl;
            return;
        }
    }

    cout<<(maxm + (n-2) / 2)<<endl;
}