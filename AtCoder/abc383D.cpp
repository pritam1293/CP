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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void primeNumbers(vector<bool> &prime,vector<int> &spf) {
    int n = prime.size();

    for(int i=2;i*i < n;i++) {
        if(prime[i]) {
            for(int j=i*i;j<n;j += i) {
                prime[j] = false;
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

void solve() {
    long long n;
    cin>>n;
    vector<bool> prime(2000002,true);
    prime[0] = false;
    prime[1] = false;

    vector<int> spf(2000002);
    for(int i=1;i<=2000002;i++) {
        spf[i] = i;
    }

    primeNumbers(prime,spf);

    int cnt = 0;

    for(long long i=2;i<2000002;i++) {
        if(i*i > n) {
            break;
        }
        else {
            int num = i / spf[i];
            if(prime[num] && num != spf[i]) {
                // cout<<i*i<<endl;
                cnt++;
            }
        }
    }

    for(int i=2;i<50;i++) {
        if(prime[i]) {
            long long num = (long long)pow(i,8);
            if(num <= n){
                cnt++;
                // cout<<num<<endl;
            }
        }
    }
    cout<<cnt<<endl;
}
