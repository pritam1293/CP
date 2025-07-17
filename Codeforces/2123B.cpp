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
    int n, j, k;
    cin>>n>>j>>k;
    j--;
    vector<int> a(n);
    int mx = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mx = max(mx, a[i]);
    }
    if(mx == a[j]) {
        cout<<"Yes"<<endl;
        return;
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(i == j) continue;
        if(mx >= a[i]) cnt++;
    }    
    cnt--;
    // cout<<cnt<<endl;
    if(cnt >= n-k) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}