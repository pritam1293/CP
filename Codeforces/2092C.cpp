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
    int maxm = 0;
    int odd = 0;
    int sum = 0;
    for(int i=0;i<n;i++) {
        int val;
        cin>>val;

        sum += val;
        maxm = max(maxm, val);
        if(val % 2) odd++;
    }
    if(odd == n || odd == 0) {
        cout<<maxm<<endl;
    }
    else{
        cout<< sum - odd + 1ll <<endl;
    }
}