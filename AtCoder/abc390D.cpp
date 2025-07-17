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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void rec(const vector<long long> &v,int idx,vector<long long> curr,vector<vector<long long>> &ans) {
    if (idx == v.size()) {
        ans.push_back(curr);
        return;
    }
    rec(v,idx+1,curr,ans);
    curr.push_back(v[idx]);
    rec(v,idx+1,curr,ans);
}

void solve() {
    int n;
    cin>>n;
    vector<long long> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<vector<long long>> subset;
    vector<long long> temp;
    rec(a,0,temp,subset);
    // for(auto it : subset) {
    //     for(auto num : it) {
    //         cout<<num<<" ";
    //     }
    //     cout<<endl;
    // }

    set<long long> ans;
    long long all_xor = 0;
    for(int i=0;i<n;i++) {
        all_xor ^= a[i];
    }
    for(auto arr : subset) {
        long long temp = all_xor;
        long long sum = 0;
        for(long long x : arr) {
            temp ^= x;
            sum += x;
        }
        temp ^= sum;
        ans.insert(temp);
    }
    cout<<ans.size()<<endl;
}
