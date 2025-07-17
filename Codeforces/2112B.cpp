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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<n;i++) {
        if(abs(a[i] - a[i-1]) <= 1) {
            cout<<0<<endl;
            return;
        }
    }
    for(int i=2;i<n;i++) {
        int x = a[i-2], y = a[i-1], z = a[i];
        if(y > z) swap(y, z);
        if((y <= x && x <= z) || (y <= x+1 && x+1 <= z) || (y <= x-1 && x-1 <= z)) {
            cout<<1<<endl;
            return;
        }
    }
    reverse(a.begin(), a.end());
    for(int i=2;i<n;i++) {
        int x = a[i-2], y = a[i-1], z = a[i];
        if(y > z) swap(y, z);
        if((y <= x && x <= z) || (y <= x+1 && x+1 <= z) || (y <= x-1 && x-1 <= z)) {
            cout<<1<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}