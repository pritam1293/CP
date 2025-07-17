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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    bool flag = true;
    for(int i=1;i<n;i++) {
        if(a[i-1] > a[i]) flag = false;
    }
    if(flag) {
        cout<<"0"<<endl;
        return;
    }   
    for(int bit = 0; bit < 31; bit++) {
        int x = (1 << (bit + 1)) - 1;
        int prev = a[0] | x;
        flag = true;
        for (int i = 1; i < n; i++) {
            int curr = a[i] | x;
            if (curr < prev) {
                flag = false;
                break;
            }
            prev = curr;
        }
        if (flag) {
            cout<< (1 << bit) <<endl;
            return;
        }
    }
}