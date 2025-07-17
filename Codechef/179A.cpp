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
    int h = a[n-1];
    int cnt = 0;
    for(int i=n-1;i>=0;i--) {
        int mx = 0;
        for(int j=0;j<i;j++) {
            mx = max(mx , a[j]);
        }
        if(mx >= h) {
            cnt++;
        }
        else {
            cout<<cnt<<endl;
            return;
        }
    }
    cout<<cnt<<endl;
}