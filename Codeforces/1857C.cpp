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
    int size = n*(n-1)/2;
    vector<int> a(size);
    for(int i = 0; i < size; i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < size; i += n) {
        cout<<a[i]<<" ";
        n--;
    }
    cout<<(int)1e9<<endl;
}