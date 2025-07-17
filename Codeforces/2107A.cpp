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
    int maxm = a[0], minm = a[0];
    for(int i=1;i<n;i++) {
        maxm = max(maxm, a[i]);
        minm = min(minm, a[i]);
    }
    if(maxm == minm) {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    for(auto& val : a) {
        if(val == maxm) {
            cout<<"1 ";
        }
        else {
            cout<<"2 ";
        }
    }
    cout<<endl;
}