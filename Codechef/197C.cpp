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

bool check(string &s, int k, int mid) {
    int cnt = 0;
    int curr = 0, zero = 0;
    for(auto& c : s) {
        if(c == '1') curr++;
        else {
            zero++;
            curr = max(curr, zero);
        }
        if(curr >= mid) {
            cnt++;
            curr = 0;
            zero = 0;
        }
    }
    return cnt >= k;
}

void solve() {
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int low = 0, high = n, ans = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(s, k, mid)) {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout<<ans<<endl;
}