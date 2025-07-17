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
    int n, m, a, b;
    cin>>n>>m>>a>>b;
    int up = m - n * a;
    int down = b-a;
    if(up >= 0 && up % down == 0 && up/down <= n) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}