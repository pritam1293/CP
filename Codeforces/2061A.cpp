#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    int odd = 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(a[i] % 2) odd++;
    }
    int even = n-odd;
    if(even == 0) {
        cout<<n-1<<endl;
    }
    else {
        cout<<odd + 1<<endl;
    }
}
