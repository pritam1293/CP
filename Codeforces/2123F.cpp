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
    //prime number indentification
    vector<bool> prime(n+1, true);
    for(int i = 2; i*i <= n; i++) {
        if(prime[i]) {
            for(int j = i*i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    vector<int> ans(n+1, -1);
    ans[1] = 1; //always
    for(int i = 2; i <= n; i++) {
        if(prime[i] && 2*i > n) ans[i] = i; //no other options
    }
    //smallest prime factor
    vector<int> spf(n+1);
    for(int i = 1; i <= n; i++) spf[i] = i;
    for(int i = 2; i*i <= n; i++) {
        if(spf[i] == i) {
            for(int j = i; j <= n; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    vector<vector<int>> div(n+1);
    for(int i = 2; i <= n; i++) {
        if(ans[i] != -1) continue;
        int j = i/spf[i];
        spf[i] = max(spf[i], spf[j]); //converting to highest prime factor
        div[spf[i]].push_back(i);
    }
    // for(int i=1;i<=n;i++) {
    //     cout<<i<<"-> ";
    //     for(auto it : div[i]) {
    //         cout<<it<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i = 2; i <= n; i++) {
        if(div[i].empty()) continue;
        int prev = div[i][0];
        for(int j = 1; j < div[i].size(); j++) {
            ans[prev] = div[i][j];
            prev = div[i][j];
        }
        ans[prev] = div[i][0];
    }
    for(int i = 1; i <= n; i++) {
        if(ans[i] == -1) ans[i] = i;
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}