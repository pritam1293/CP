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
    int k, a, b, x, y;
    cin>>k>>a>>b>>x>>y;
    if(x > y) {
        swap(x, y);
        swap(a, b);
    }
    int cnt = 0;
    if(k >= a) cnt += (k-a)/x +1;
    k -= cnt * x;
    if(k >= b) cnt += (k-b)/y +1;
    cout<<cnt<<endl;
}