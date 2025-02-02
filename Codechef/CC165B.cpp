#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
    
    // int curr = a[n-1];
    int ans = 0;
    int cnt = 0;
    int prev = a[n-1];

    for(int i=n-2;i>=0;i--) {
        if(prev > a[i]) cnt++;
        else {
            ans = max(ans , cnt);
            prev = a[i];
            cnt = 0;
        }
    }
    ans = max(cnt , ans);
    cout<<ans<<endl;
}
