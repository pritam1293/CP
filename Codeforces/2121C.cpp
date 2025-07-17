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
    vector<vector<int>> a(n, vector<int>(m));
    int mx = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
            mx = max(mx, a[i][j]);
        }
    }
    vector<int> row(n, 0), col(m, 0);
    int cnt = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(a[i][j] == mx) {
                cnt++;
                row[i]++;
            }
        }
    }
    for(int j=0;j<m;j++) {
        for(int i=0;i<n;i++) {
            if(a[i][j] == mx) {
                col[j]++;
            }
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            int temp = row[i] + col[j] - (a[i][j] == mx);
            if(temp == cnt) {
                cout<<mx-1<<endl;
                return;
            }
        }
    }
    cout<<mx<<endl;
}