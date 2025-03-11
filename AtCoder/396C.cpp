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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n,m;
    cin>>n>>m;
    priority_queue<long long> black , white;
    for(int i=0;i<n;i++) {
        long long num;
        cin>>num;
        black.push(num);
    }
    for(int i=0;i<m;i++) {
        int num;
        cin>>num;
        white.push(num);
    }
    long long ans = 0;
    while(!black.empty() && !white.empty()) {
        if(black.top() > 0 && white.top() > 0) {
            ans += (black.top() + white.top());
            black.pop();
            white.pop();
        }
        else if(black.top() > 0) {
            ans += black.top();
            black.pop();
        }
        else if(white.top() > 0 && white.top() > abs(black.top())) {
            ans += (black.top() + white.top());
            black.pop();
            white.pop();
        }
        else {
            break;
        }
    }
    while(!black.empty() && black.top() > 0) {
        ans += black.top();
        black.pop();
    }
    cout<<ans;
}