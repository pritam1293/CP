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
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> ans(n, vector<int>(m));
    vector<int> a(k), b(k);
    for(int i = 0 ;i < k; i++) a[i] = i+1;
    b[k-1] = 1;
    for(int i = 1; i < k; i++) b[i-1] = i+1;

    int idx = 0;
    bool flag = true;

    if(m % k == 0) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(flag) ans[i][j] = a[idx % k];
                else ans[i][j] = b[idx % k];
                idx++;
            }
            flag = !flag;
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans[i][j] = a[idx % k];
                idx++;
            }
        }
    }
    for(auto& it : ans) {
        for(auto& i : it) {
            cout<<i<<" ";
        }
        cout<<endl;
    }
    // cout<<endl;
}