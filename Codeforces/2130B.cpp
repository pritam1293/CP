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
    int n, s;
    cin>>n>>s;
    int sum = 0;
    int c = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        sum += a[i];
        if(a[i] == 0) c++;
    }
    if(s == sum+1 || sum > s) {
        sort(a.rbegin(), a.rend());
        int i = 0;
        while(c--) {
            cout<<"0 ";
        }
        while(a[i] != 0) {
            cout<<a[i]<<" ";
            i++;
        }
        cout<<endl;
    }
    else {
        cout<<"-1"<<endl;
    }
}