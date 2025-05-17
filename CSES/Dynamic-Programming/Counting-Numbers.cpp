#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int dp[20][10][2][2];

int rec(string &s, int curr, int prev, int zero, int tight) {
    if(curr == 0) return 1;

    if(dp[curr][prev][zero][tight] == -1) {
        int limit;
        if(tight == 0) limit = 9;
        else {
            int size = s.size();
            limit = s[size-curr] - '0';
        }

        int cnt = 0;
        for(int digit = 0; digit <= limit; digit++) {
            if(zero == 0 && digit == prev) continue;

            int new_zero = (zero == 1 && digit == 0) ? 1 : 0;
            int new_tight = (digit == limit && tight == 1) ? 1 : 0;

            cnt += rec(s, curr-1,digit, new_zero, new_tight);
        }
        dp[curr][prev][zero][tight] = cnt;
    }
    return dp[curr][prev][zero][tight];
}
  
void solve() {
    int a, b;
    cin>>a>>b;
    memset(dp, -1, sizeof(dp));
    string s = to_string(a-1);
    int cnt1 = 0;
    if(a != 0) cnt1 = rec(s, s.size(), -1, 1, 1);
    memset(dp, -1, sizeof(dp));
    s = to_string(b);
    int cnt2 = rec(s, s.size(), -1, 1, 1);
    cout<< cnt2 - cnt1 <<endl;
}