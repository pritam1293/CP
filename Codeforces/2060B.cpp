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
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++) {
        sort(a[i].begin(),a[i].end());
    }
    // for(int i=0;i<n;i++) {
    //     for(int j=0;j<m;j++) {
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=0;i<n;i++) {
        for(int j=1;j<m;j++) {
            if(a[i][j] - a[i][j-1] != n) {
                cout<<-1<<endl;
                return;
            }
        }
    }
    vector<int> per(n);
    for(int i=0;i<n;i++) {
        per[a[i][0]] = i+1;
    }
    for(int x : per) {
        cout<<x<<" ";
    }
    cout<<endl;
}
