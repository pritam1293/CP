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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int st = 0 , end = n-1;
    int cnt = 0;
    while(st < end) {
        int sum = a[st] + a[end];
        if(sum == k) {
            cnt++;
            st++;
            end--;
        }
        else if(sum > k) end--;
        else st++;
    }
    cout<<cnt<<endl;
}
