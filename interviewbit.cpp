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

int longestSubsequenceLength(const vector<int> &a) {
    int n = a.size();
    vector<int> lis(n, 1), lds(n, 1);
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++) {
            if(a[i] > a[j]) {
                lis[i] = max(lis[i] , 1 + lis[j]);
            }
        }
    }
    
    for(int i=n-1;i>=0;i--) {
        for(int j=n-1;j>i;j--) {
            if(a[i] > a[j]) {
                lds[i] = max(lds[i], 1 + lds[j]);
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++) {

        cout<<lds[i]<<" ";
        ans = max(ans , lis[i] + lds[i] - 1);
    }
    cout<<endl;
    return ans;
}


void solve() {
    vector<int> a = {1, 11, 2, 10, 4, 5, 2, 1};
    cout<<longestSubsequenceLength(a)<<endl;
}
