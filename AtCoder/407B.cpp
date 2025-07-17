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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int x, y;
    cin>>x>>y;
    double cnt = 0;
    for(int i=1;i<=6;i++) {
        for(int j=1;j<=6;j++) {
            if(i + j >= x || abs(i-j) >= y) cnt++;
        }
    }
    double total = 36;
    double ans = cnt / total;
    cout<<setprecision(15)<<ans<<endl;
}