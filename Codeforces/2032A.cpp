#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
    int cnt0 = 0;
    for(int i=0;i<2*n;i++) {
        cin>>a[i];
        if(a[i] == 0) cnt0++;
    }
    int cnt1 = 2*n-cnt0;
    int minm = 0 , maxm = 0;
    if(cnt0 % 2 == 0 && cnt1 % 2 == 0) minm = 0;
    else minm = 1;
    maxm = min(cnt0,cnt1);
    cout<<minm<<" "<<maxm<<endl;
}
