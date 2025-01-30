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
    vector<int> a(5);
    cin>>a[0]>>a[1]>>a[3]>>a[4];

    int ans = 0;
    a[2] = a[0]+a[1];
    int cnt = 0;
    for(int i=0;i<3;i++) {
        if(a[i+2] == a[i] + a[i+1]) cnt++;
    }
    ans = max(ans,cnt);

    a[2] = a[3]-a[1];
    cnt = 0;
    for(int i=0;i<3;i++) {
        if(a[i+2] == a[i] + a[i+1]) cnt++;
    }
    ans = max(ans,cnt);

    a[2] = a[4]-a[3];
    cnt = 0;
    for(int i=0;i<3;i++) {
        if(a[i+2] == a[i] + a[i+1]) cnt++;
    }
    ans = max(ans,cnt);

    cout<<ans<<endl;
}
