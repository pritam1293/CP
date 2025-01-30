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

int xorAll(vector<int> &a,vector<int> &b) {
        int n = a.size() , m = b.size();
        int ans = 0;
        if(n % 2) {
            for(int i=0;i<m;i++) {
                ans ^= b[i];
            }
        }
        if(m % 2) {
            for(int i=0;i<n;i++) {
                ans ^= a[i];
            }
        }
        return ans;
}

void solve() {
    vector<int> a = {2,1};
    vector<int> b = {3,4};
    cout<<xorAll(a,b)<<endl;
}
