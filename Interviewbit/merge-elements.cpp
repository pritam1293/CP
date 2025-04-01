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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int mergeElements(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n));
    /*
    defination- 2D vector to denote minimum cost of merging starting from 
    index-i to index-j  -> that is why 2D dynamic array
    */
    vector<int> prefix(n+1);//prefix sum
    for(int i=0;i<n;i++) {
        prefix[i+1] = a[i] + prefix[i];
    }

    for(int diff=1;diff<n;diff++) {
        int i = 0;
        int j = diff;

        while(j < n) {
            dp[i][j] = INT_MAX;
            for(int k=i;k<j;k++) {
                int cost = prefix[j+1]-prefix[i] + dp[i][k] + dp[k+1][j];
                dp[i][j] = min(dp[i][j], cost);
            }
            i++;
            j++;
        }
    }
    return dp[0][n-1];
}

void solve() {
    vector<int> a = {4, 9, 13, 15, 6 };
    cout<<mergeElements(a)<<endl;
}