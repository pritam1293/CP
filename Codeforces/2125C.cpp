#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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

int fnc(int n) {
    int ans = n;
    vector<int> pf = {2, 3, 5, 7};
    for(int i = 0; i < 4; i++) {
        ans -= n / pf[i];
    }
    for(int i = 0; i < 4; i++) {
        for(int j = i+1; j < 4; j++) {
            ans += n / (pf[i] * pf[j]);
        }
    }
    for(int i = 0; i < 4; i++) {
        for(int j = i+1; j < 4; j++) {
            for(int k = j+1; k < 4; k++) {
                ans -= n / (pf[i] * pf[j] * pf[k]);
            }
        }
    }
    ans += n / (2*3*5*7);
    return ans;
}

void solve() {
    int l, r;
    cin>>l>>r;
    // cout<<l<<" "<<r<<endl;
    cout<< fnc(r) - fnc(l-1ll) <<endl;
}