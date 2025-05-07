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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    int i = 0;
    int cnt = 0;
    for(int j=0;j<m;j++) {
        while(i < n && a[i] < b[j]) {
            cnt++;
            i++;
        }
        cout<<cnt<<" ";
    }
}