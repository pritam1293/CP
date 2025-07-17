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
    int n,k;
    cin>>n>>k;
    int op = 0;
    if(n % 2 == 1) {
        if(k % 2 == 1) {
            n  = max(0, n-k);
        }
        else {
            n = max(0, n-k+1);
        }
        op++;
    }
    if(k % 2 == 1) k--;
    op += (n+k-1)/k;
    cout<<op<<endl;
}