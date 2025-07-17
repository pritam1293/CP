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
    int n;
    cin>>n;
    cout<< 2*n <<endl;
    int j = 0;
    for(int i=1;i<=n;i++) {
        cout<<i<<" "<<"1 "<<n-j<<endl;
        cout<<i<<" "<<min(n, n-j+1)<<" "<<n<<endl;
        j++;
    }
}