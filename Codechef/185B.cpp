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
    int n, health;
    cin>>n>>health;
    vector<int> s(n), d(n);
    int one = 0, two = 0;
    for(int i=0;i<n;i++) {
        cin>>s[i]>>d[i];
        if(s[i] == 1) one = max(one, d[i]);
        else two = max(two, d[i]);
    }
    int time = 0;
    if(two >= 2 * one) {
        int cnt = health / two;
        time = 2 * cnt;
        health %= two;
    }
    else {
        time = health / one;
        health %= one;
    }
    if(health != 0) {
        if(one >= health) time++;
        else time += 2;
    }
    cout<<time<<endl;
}