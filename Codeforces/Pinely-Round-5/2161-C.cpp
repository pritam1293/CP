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
    int n, x;
    cin>>n>>x;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        sum += a[i];
    }
    int k = sum / x;
    sort(a.begin(), a.end());
    int bonus = 0;
    for(int i = n-k; i < n; i++) {
        bonus += a[i];
    }
    int first = 0, second = n-k;
    vector<int> ans;
    int curr = 0;
    for(int i = 0; i < n; i++) {
        if(first < n-k) {
            int r = curr % x;
            if(r + a[first] < x) {
                ans.push_back(a[first]);
                curr += a[first];
                first++;
            }
            else {
                ans.push_back(a[second]);
                curr += a[second];
                second++;
            }
        }
        else {
            ans.push_back(a[second]);
            curr += a[second];
            second++;
        }
    }
    cout<<bonus<<endl;
    for(auto& e : ans) {
        cout<<e<<" ";
    }
    cout<<endl;
}