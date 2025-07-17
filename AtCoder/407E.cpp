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
int n;
int s;

int rec(int i, int cnt, int sum, vector<int> &a) {
    if(i == s && cnt == n) {
        return sum;
    }
    if(i == s || cnt == n) return 0;
    //take
    int ans = rec(i+1, cnt+1, sum + a[i], a);
    //not take
    ans = max(ans, rec(i+1, cnt, sum, a));
    return ans;
}

void solve() {
    cin>>n;
    s = 2 * n;
    vector<int> a(s);
    for(int i=0;i<s;i++) {
        cin>>a[i];
    }
    cout<<rec(1, 1, a[0], a)<<endl;
}