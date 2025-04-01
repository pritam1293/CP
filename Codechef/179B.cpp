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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> b(n);
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }

    int moves = 0;
    int mn = INT_MAX;
    for(int i=0;i<n;i++) {
        int m1 = abs(a[i] - b[i]);
        int m2 = 9 - abs(a[i] - b[i]);

        moves += min(m1, m2);

        mn = min(mn, abs(m1-m2));
    }
    int rem = k - moves;
    if(rem < 0) {
        cout<<"No"<<endl;
        return;
    }
    if(rem % 2 == 0) {
        cout<<"Yes"<<endl;
        return;
    }
    if(rem < mn) {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
}