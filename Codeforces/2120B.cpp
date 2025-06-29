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
    int n, s;
    cin>>n>>s;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        int d1, d2, x, y;
        cin>>d1>>d2>>x>>y;
        if(x+y == s && (d1 * d2 == -1)) cnt++;
        else if(x == y && d1 * d2 == 1) cnt++;
    }
    cout<<cnt<<endl;
}