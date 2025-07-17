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
    long long n;
    cin>>n;
    long long ans = 1;
    long long val = 1;

    while(n >= 4) {
        ans += val;
        val *= 2ll;
        n /= 4ll;
    }
    cout<<ans<<endl;

}
