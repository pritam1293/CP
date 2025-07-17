#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int mod = 1e9 + 7;

void primeFactors(vector<map<int,int>> &v) {
    int n = 1e5;
    for(int i=2;i<=n;i++) {
        if(v[i].empty()) {
            for(int j=i;j<=n;j += i) {
                int cnt = 0 , num = j;
                while(num % i == 0) {
                    cnt++;
                    num /= i;
                }
                v[j][i] = cnt;
            }
        }
    }
}

void factorialFactors(int m,map<int,int> &fact,vector<map<int,int>> v) {
    for(int i=2;i<=m;i++) {
        for(auto it : v[i]) {
            fact[it.first] += it.second;
        }
    }
}

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<map<int,int>> prime_factors(100001);
    primeFactors(prime_factors);
    map<int,int> fact;
    factorialFactors(m,fact,prime_factors);

    for(int x : a) {
        auto temp = fact;
        for(auto it : prime_factors[x]) {
            temp[it.first] += it.second;
        }
        int ans = 1;
        for(auto it : temp) {
            ans = ((ans % mod) * ((it.second + 1) % mod)) % mod;
        }
        cout<<ans<<" ";
    }
}
