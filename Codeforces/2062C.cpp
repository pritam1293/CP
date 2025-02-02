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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }

    if(n == 1) {
        cout<<a[0]<<endl;
        return;
    }
    int max_sum = 0;
    for(int i=0;i<n;i++) {
        max_sum += a[i];
    }

    for(int i=1;i<n;i++) {
        vector<int> curr = a;
        for(int j=0;j<i;j++) {
            if(curr.size() == 1) break;
            if(curr[0] > curr.back()) {
                reverse(curr.begin(),curr.end());
            }

            vector<int> diff;
            for(int k=1;k<curr.size();k++) {
                diff.push_back(curr[k] - curr[k-1]);
            }
            curr = diff;
        }
        int sum = 0;
        for(int x : curr) {
            sum += x;
        }
        max_sum = max(max_sum , sum);
    }
    cout<<max_sum<<endl;
}
