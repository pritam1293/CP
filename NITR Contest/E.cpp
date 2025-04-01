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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    long long sum = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    int s = 0 , p = 0;
    int curr = 0;
    for(int i=0;i<n;i++) {
        sum -= a[i];
        if(curr > sum) p++;
        else if(curr < sum) s++;
        else {
            p++;s++;
        }
        curr += a[i];
    }

    string ans;

    if(s > p) {
        ans = "S";
    }
    else if(s < p) {
        ans = "P";
    }
    else {
        ans = "D";
    }

    cout<<ans<<endl;
}