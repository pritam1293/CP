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

int h = 1;
int w = 1;
int inf = 0;

void solve() {
    // long long n,b,c;
    // cin>>n>>b>>c;

    // if(b == 0ll) {
    //     if(c == n-1ll || c == n-2ll) {
    //         cout<< n-1ll <<endl;
    //     }
    //     else if(c >= n) {
    //         cout<<n<<endl;
    //     }
    //     else {
    //         cout<<-1<<endl;
    //     }
    //     return;
    // }

    // long long present = (n-1ll-c+b) / b;
    
    // cout<<n-max(0ll , present)<<endl;
        vector d(h, vector<int>(w, inf));

}
