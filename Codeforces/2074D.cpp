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

void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> center(n),radius(n);
    for(int i=0;i<n;i++) {
        cin>>center[i];
    }
    for(int i=0;i<n;i++) {
        cin>>radius[i];
    }

    map<int,vector<pair<int,int>>> points;

    for(int i=0;i<n;i++) {
        int x = center[i];
        int r = radius[i];

        for(int p = x-r; p <= x+r; p++) {

            int sq = max(0ll , r*r - (x-p)*(x-p) );
            int y = sqrt(sq);

            points[p].push_back({-y , y});
        }
    }

    long long ans = 0;
    for(auto &point : points) {

        auto &range = point.second;
        sort(range.begin(),range.end());

        int cnt = 0;
        int size = range.size();
        int st = range[0].first , end = range[0].second;

        for(int i=1;i<size;i++) {

            if(range[i].first <= end + 1ll) {
                end = max(range[i].second , end);
            }
            else {
                cnt += end - st + 1ll;
                st = range[i].first;
                end = range[i].second;
            }
        }
        cnt += end - st + 1ll;
        ans += cnt;
    }

    cout<<ans<<endl;
}