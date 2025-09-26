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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int count(vector<int> &a) {
    int n = a.size();
    int mid = n/2;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(a[i] - (a[mid] + i - mid));
    }
    return ans;
}

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a, b;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') a.push_back(i);
        else b.push_back(i);
    }
    cout<< min(count(a), count(b)) <<endl;
}