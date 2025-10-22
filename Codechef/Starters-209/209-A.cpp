#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int find(vector<int> &a, int n) {
    int mx = -1;
    int idx = -1;
    for(int i = 0; i < n; i++) {
        if(a[i] > mx) {
            mx = a[i];
            idx = i+1;
        }
    }
    a[idx-1] = -1;
    return idx;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = __gcd(i+1, n);
    }
    for(int i = 0; i < n; i++) {
        cout<<find(a, n)<<" ";
    }
    cout<<endl;
}