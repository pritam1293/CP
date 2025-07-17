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
    double a, b;
    cin>>a>>b;
    double div = a/b;
    int ans = div;
    div -= (double)ans;
    if(div >= 0.5) {
        cout<<ans +1 <<endl;
    }
    else {
        cout<<ans<<endl;
    }
}