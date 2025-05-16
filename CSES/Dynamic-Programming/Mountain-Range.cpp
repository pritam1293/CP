#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
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
    int val = a[0];
    int cnt = 1;
    int ans = 1;
    for(int i=1;i<n;i++) {
        if(a[i] < val) cnt++;
        else {
            ans = max(ans, cnt);
            val = a[i];
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout<<ans<<endl;
}