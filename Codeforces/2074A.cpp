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
    int l,r,d,u;
    cin>>l>>r>>u>>d;
    int dis = r*r + u*u;
    if(u*u + l*l == dis && l*l + d*d == dis && d*d + r*r == dis && u+d == l+r) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }
}