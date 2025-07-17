#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
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

bool check(vector<int> &a, int n) {
    vector<int> cnt(10);
    for(int i=0;i<=n;i++) {
        cnt[a[i]]++;
    }
    return (cnt[0] >= 3 && cnt[1] >= 1 && cnt[2] >= 2 && cnt[3] >= 1 && cnt[5] >= 1);
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int idx = 0;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(idx == 0 && check(a,i)) idx = i+1;
    }
    cout<<idx<<endl;
}