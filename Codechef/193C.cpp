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
    int n, k;
    cin>>n>>k;
    vector<int> ans(n+1);
    for(int i = 0; i <= n; i++) ans[i] = i;
    int i = 1;
    k--;
    while(k--) {
        cout<<ans[i]<<" ";
        i++;
    }
    for(int j = n ; j >= i; j--) {
        cout<<ans[]<<" ";
    }
    cout<<endl;
}