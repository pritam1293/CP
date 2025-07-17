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
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> pmin(n), pmax(n);
    pmin[0] = a[0];
    for(int i=1;i<n;i++) {
        pmin[i] = min(pmin[i-1], a[i]);
    }
    pmax[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--) {
        pmax[i] = max(pmax[i+1], a[i]);
    }   
    for(int i=0;i<n;i++) {
        int left = (i == 0 ? 1e9 : pmin[i-1]);
        int right = (i == n-1 ? 0: pmax[i+1]);
        if(a[i] < left || a[i] > right) {
            cout<<"1";
        }
        else {
            cout<<"0";
        }
    }
    cout<<endl;
}