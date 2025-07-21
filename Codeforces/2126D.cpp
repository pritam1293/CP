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
    int n, k;
    cin>>n>>k;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i = 0; i < n; i++) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    sort(a.begin(), a.end());
    int i = 0;
    priority_queue<int> pq;
    while(true) {
        while(i < n && a[i][0] <= k) {
            pq.push(a[i][2]);
            i++;
        }
        while(!pq.empty() && pq.top() <= k) {
            pq.pop();
        }
        if(pq.empty()) break;
        k = pq.top();
        pq.pop();
    }
    cout<<k<<endl;
}