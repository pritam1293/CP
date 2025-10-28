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

vector<int> binary(int n) {
    vector<int> ans;
    while(n) {
        ans.push_back(n % 2);
        n /= 2;
    }
    return ans;
}

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> a = binary(n);
    vector<int> b = binary(m);
    if((int)b.size() > (int)a.size()) {
        cout<<"-1"<<endl;
        return;
    } 
    vector<int> diff((int)a.size());
    int i = 0;
    for(; i < (int)b.size(); i++) {
        if(a[i] != b[i]) {
            diff[i] = 1;
        }
    }
    while(i < (int)a.size()) {
        diff[i] = a[i];
        i++;
    }
    // for(int j = 0; j < (int)a.size(); j++) {
    //     cout<< (a[j] ^ diff[j]) <<" ";
    // }
    // cout<<endl;
    // for(auto it : b) {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // cout<<endl;
    vector<int> ans;
    for(int j = 0; j < (int)a.size(); j++) {
        if(diff[j]) ans.push_back(pow(2, j));
    }
    cout<< (int)ans.size() <<endl;
    for(auto& e : ans) {
        cout<<e<<" ";
    }
    if(!ans.empty()) {
        cout<<endl;
    }
}