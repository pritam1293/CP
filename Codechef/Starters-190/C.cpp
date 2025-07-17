#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
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
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> b(n);
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    priority_queue<int> pq;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        int low = x - a[i];
        while(cnt > low && !pq.empty()) {
            pq.pop();
            cnt--;
        } 
        if(x - cnt >= b[i]) {
            pq.push(b[i]);
            cnt++;
        }
    }
    cout<<cnt<<endl;
}