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

bool isZero(vector<int> &a) {
    for(int val : a) {
        if(val != 0) return false;
    }
    return true;
} 

int minZeroArray(vector<int>& a, vector<vector<int>>& queries) {
    int k = 0;
    for(auto q : queries) {
        int l = q[0];
        int r = q[1];
        int val = q[2];

        k++;

        for(int i=l;i<=r;i++) {
            a[i] -= val;
            a[i] = max(0, a[i]);
        }
        if(isZero(a)) return k;
    }
    return -1;
}

void solve() {
    vector<int> a = {1,2,3,2,1};
    vector<vector<int>> q = {{0,1,1},{1,2,1},{2,3,2},{3,4,1},{4,4,1}};
    cout<<minZeroArray(a, q);
}
