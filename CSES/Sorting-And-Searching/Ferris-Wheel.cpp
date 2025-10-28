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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    int left = 0, right = n-1;
    while(left <= right) {
        int sum = a[left] + a[right];
        if(sum <= k) {
            left++;
            right--;
            cnt++;
        }
        else {
            right--;
            cnt++;
        }
    }
    cout<<cnt<<endl;    
}