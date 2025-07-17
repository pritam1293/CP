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
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<long long> premax(n);
    premax[0] = a[0];
    for(int i=1;i<n;i++) {
        premax[i] = max(a[i], premax[i-1]);
    }
    long long sum = 0;
    for(int i=n-1;i>=0;i--) {
        cout<< sum + premax[i] <<" ";
        sum += a[i];
    }
    cout<<endl;
}