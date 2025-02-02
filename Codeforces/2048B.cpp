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
    int n,k;
    cin>>n>>k;
    int val = 1;
    vector<int> ans(n+1 , -1);
    for(int i=k;i<=n;i += k) {
        ans[i] = val;
        val++;
    }
    for(int i=1;i<=n;i++) {
        if(ans[i] == -1) {
            ans[i] = val;
            val++;
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
