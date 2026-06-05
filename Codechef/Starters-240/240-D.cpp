#include<bits/stdc++.h>
using namespace std;
#define int long long

void precompute();
void solve();

int32_t main() {
    precompute();
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

const int m = 1e6;
vector<int> pre(m+1);

void precompute() {
    vector<int> tao(m+1);
    vector<int> primes;
    vector<bool> prime(m+1, true);
    vector<int> power(m+1);

    tao[1] = 1;
    prime[0] = false;
    prime[1] = false;
    for(int i = 2; i <= m; i++) {
        if(prime[i]) {
            primes.push_back(i);
            tao[i] = 3;
            power[i] = 1;
        }
        for(auto& p : primes) {
            if(i*p > m) {
                break;
            }
            prime[i*p] = false;

            if(i % p == 0) {
                power[i*p] = power[i] + 1;
                tao[i*p] = tao[i] / (2 * power[i] + 1) * (2 * power[i*p] + 1);
                break;
            }
            else {
                power[i*p] = 1;
                tao[i*p] = tao[i] * 3;
            }
        }
    }
    for(int i = 1; i <= m; i++) {
        pre[i] = pre[i-1] + tao[i];
    }
}

void solve() {
    int z;
    cin>>z;
    cout<< z*z - pre[z] <<endl;
}