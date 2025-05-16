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

struct event {
    int start, end, reward;
};

static bool compare(const event &a, const event &b) {
    return a.start < b.start;
}

int rec(int i, int n, vector<event> &events, vector<int> &dp) {
    if(i == n) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = rec(i+1, n, events, dp);
    event e = {events[i].end+1, events[i].end+1, 0};
    int idx = lower_bound(events.begin(), events.end(), e, compare) - events.begin();
    if(idx != n) {
        ans = max(ans, events[i].reward + rec(idx, n, events, dp));
    }
    else {
        ans = max(ans, events[i].reward);
    }
    return dp[i] = ans;
}

void solve() {
    int n;
    cin>>n;
    vector<event> events(n);
    for(int i=0;i<n;i++) {
        cin>>events[i].start>>events[i].end>>events[i].reward;
    }
    sort(events.begin(), events.end(), compare);
    vector<int> dp(n+1, -1);
    cout<<rec(0, n, events, dp)<<endl;
}