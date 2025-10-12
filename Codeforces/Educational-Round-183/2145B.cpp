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
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    if(n == k) {
        while(n--) {
            cout<<"-";
        }
        cout<<endl;
        return;
    }
    int o = 0, z = 0, t = 0;
    for(auto& c : s) {
        if(c == '0') z++;
        else if(c == '1') o++;
        else t++;
    }
    vector<char> ans(n, '+');
    int left = 0;
    while(z--) {
        ans[left++] = '-';
    }
    int right = n-1;
    while(o--) {
        ans[right--] = '-';
    }
    for(int i = 0; i < t; i++) {
        ans[left + i] = '?';
        ans[right - i] = '?';
    }
    for(auto& c : ans) {
        cout<<c;
    }
    cout<<endl;
}