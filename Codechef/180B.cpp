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

long long mod = 998244353;

long long power(long long x, long long y) { 
    int ans = 1;
    x = x % mod;
 
    if (x == 0) return 0;

    while (y > 0) { 
        if (y & 1) {
            ans = ((ans % mod)  * (x % mod)) % mod; 
        }

        y = y>>1;
        x = ((x % mod) * (x % mod)) % mod; 
    } 
    return ans; 
} 

void solve() {
    long long n;
    cin>>n;
    long long ans;
    if(n % 2 == 1){
        ans = power(2, n-1);
    } 
    else {
        ans = (3 * power(2, n-2)) % mod;
    }
    cout<<ans<<endl;
}