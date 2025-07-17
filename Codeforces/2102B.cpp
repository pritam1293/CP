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
        a[i] = abs(a[i]);
    }
    // if(n == 1) {
    //     cout<<"YES"<<endl;
    //     return;
    // }
    int num = a[0];
    sort(a.begin(),a.end());
    int x = a[n/2];
    if(x >= num) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}