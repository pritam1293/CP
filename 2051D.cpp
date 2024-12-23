#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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
    int n,x,y;
    cin>>n>>x>>y;
    int sum = 0;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    
    sort(a.begin(),a.end());

    int upper = sum - x;
    int lower = sum - y;

    // lower <= pair_sum <= upper
    int ans = 0;
    int l = 0 , r = n-1;

    while(l < r) {
        if(a[l] + a[r] <= upper) {
            ans += r-l;
            l++;
        }
        else r--;
    }

    l = 0; 
    r = n-1;

    while(l < r) {
        if(a[l] + a[r] < lower) {
            ans -= r-l;
            l++;
        }
        else {
            r--;
        } 
    }

    cout<<ans<<endl;

}
