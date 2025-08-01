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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

long long numOfSubsequences(string s) {
    int n = s.size();
    vector<long long> lc(n);
    int l = 0;
    if(s[0] == 'L') l++;
    for(int i = 1; i < n; i++) {
        if(s[i] == 'L') l++;
        if(s[i] == 'C') {
            lc[i] = lc[i-1] + (long long)l;
        }
        else lc[i] = lc[i-1];
    }
    cout<<lc[n-1]<<endl;
    vector<long long> lct(n);
    for(int i = 1; i < n; i++) {
        if(s[i] == 'T') {
            lct[i] = lct[i-1] + lc[i];
        }
        else lct[i] = lct[i-1];
    }
    cout<<lct[n-1]<<endl;
    return 0;
}

void solve() {
    string s = "LCCTTLCT";
    cout<<numOfSubsequences(s)<<endl;
}