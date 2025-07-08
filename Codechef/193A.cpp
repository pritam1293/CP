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
    int odd = 0, even = 0;
    for(int i = 1; i <= n; i++) {
        if(n%i == 0) {
            if(i % 2) odd++;
            else even++;
        } 
    }
    cout<<odd<<" "<<even<<endl;
}