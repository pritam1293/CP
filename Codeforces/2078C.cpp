#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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
    vector<int> a(2*n);
    for(int i=0;i< 2*n;i++) {
        cin>>a[i];
    }
    sort(a.rbegin(),a.rend());
    int num = 0;
    for(int i=0;i<=n;i++) {
        num += a[i];
    }
    for(int i=n+1;i<2*n;i++) {
        num -= a[i];
    }
    cout<<a[0]<<" "<<num<<" ";
    int i = 1 , j = 2*n - 1;
    while(i < j) {
        cout<<a[i++]<<" "<<a[j--]<<" ";
    }
    cout<<a[j]<<endl;
}