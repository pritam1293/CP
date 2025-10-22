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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, x, k;
    cin>>n>>x>>k;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) {
        int v;
        cin>>v;
        pq.push(v);
    }
    while(k) {
        x += 100;
        pq.pop();
        k--;
    }
    int rank = 0;
    while(!pq.empty()) {
        if(pq.top() > x) {
            rank++;
            pq.pop();
        }
        else break;
    }
    cout<< rank + 1 <<endl;
}