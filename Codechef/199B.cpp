#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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
    int n;
    cin>>n;
    // cout<<n<<endl;
    if(n%2 == 1) {
        cout<< (n+1)/2 <<endl;
    }
    else {
        int cnt = n/2;
        if((n/2) % 2 == 0) n -= 2;
        n /= 2;
        cnt += (n+1)/2;
        cout<<cnt<<endl;
    }
}