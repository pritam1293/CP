#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
    int tar = a[0];
    int diff = 1e7;
    int x = -1;
    for(int i=1;i<n;i++) {
        int temp = tar - a[i];
        if(temp > 0 && temp < diff) {
            x = a[i];
            diff = temp;
        }
    }
    diff = 1e7;
    int y = -1;
    for(int i=1;i<n;i++) {
        int temp = a[i] - tar;
        if(temp > 0 && temp < diff) {
            y = a[i];
            diff = temp;
        }
    }

    int ans = 0;
    if(x == -1) {
        ans = tar-1;
        for(int i=tar;i<=y;i++) {
            if(i-tar <= y-i) ans++;
        }
    }
    else if(y == -1) {
        ans = 1000000-tar;
        for(int i=x;i<=tar;i++) {
            if(tar-i <= i-x) ans++;
        }
    }
    else{
        for(int i=tar+1;i<=y;i++) {
            if(i-tar <= y-i) {
                ans++;
            }
        }
        for(int i=x;i<=tar;i++) {
            if(tar-i <= i-x) {
                ans++;
            }
        }
    }
    // cout<<x<<" "<<tar<<" "<<y<<endl;
    cout<<ans<<endl;
}