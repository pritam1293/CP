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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, l, r;
    cin>>n>>l>>r;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin>>x>>y;
        if((x <= l && l <= y) && (x <= r && r <= y)) cnt++;
    }
    cout<<cnt<<endl;
}