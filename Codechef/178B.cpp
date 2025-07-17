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
    if(n % 2 == 0) {
        n--;
    }
    if(n-2 < k) {
        cout<<"-1 -1"<<endl;
        return;
    }
    if(n*2 - 1 < 2*k) {
        cout<<"-1 -1"<<endl;
        return;
    }
    cout<<"2 "<<n<<endl;
}