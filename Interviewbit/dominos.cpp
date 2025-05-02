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
    int n = 12;
    int mod = 1e9 + 7;
    vector<int> a(n+1), b(n+1);
    /*
    1. a[n] = a[n-2] + b[n-1] + c[n-1] and b & c are basically same with 
    opposite structure, so b & c will give the same values

    2. b[n] = a[n-1] + b[n-2];

    3. for visual representation see the page:-
     https://www.geeksforgeeks.org/tiling-with-dominoes/?ref=gcse_ind
    */
    a[0] = 1, a[1] = 0, b[0] = 0, b[1] = 1;

    for(int i=2;i<=n;i++) {
        a[i] = ((a[i-2] % mod) + (2 * (b[i-1] % mod)) % mod) % mod;
        b[i] = ((a[i-1] % mod) + (b[i-2] % mod)) % mod;
    }
    cout<<a[n]<<endl;
}