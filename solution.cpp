#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            swap(a[i][j], a[j][i]);
        }
    }
    int i = 0, j = n-1;
    while(i < j) {
        for(int k = 0; k < n; k++) {
            swap(a[k][i], a[k][j]);
        }
        i++;j--;
    }
    for(auto& arr : a) {
        for(auto& e : arr) {
            cout<<e<<" ";
        }
        cout<<endl;
    }
}