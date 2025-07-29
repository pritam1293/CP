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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    int l = 0, r = n-1;
    string s;
    bool flag = false;
    while(l <= r) {
        if(flag) {
            //take min
            if(a[l] > a[r]) {
                s += "R";
                // cout<<a[r]<<" ";
                r--;
            }
            else {
                s += "L";
                // cout<<a[l]<<" ";
                l++;
            }
            flag = false;
        }
        else {
            //take max
            if(a[l] > a[r]) {
                s += "L";
                // cout<<a[l]<<" ";
                l++;
            }
            else {
                s += "R";
                // cout<<a[r]<<" ";
                r--;
            }
            flag = true;
        }
    }
    // cout<<endl;
    cout<<s<<endl;
}