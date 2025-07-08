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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int count(long long val, vector<vector<int>> &mat, int m, int n) {
    int cnt = 0;
    for(int i = 0; i < m; i++) {
        int idx = -1;
        int low = 0, high = n-1, mid;
        while(low <= high) {
            mid = (low + high) / 2;
            if(mat[i][mid] <= val) {
                idx = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        cnt += idx+1;
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    long long low = 0, high = 1e9, mid;
    int tar = (m*n)/2;
    long long ans = 0;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(count(mid, matrix, n, n) <= tar) {
            low = mid+1;
            ans = mid;
        } 
        else high = mid-1;
    }
    return (int)ans;
}

void solve() {
    // int m , n;
    // cin>>m>>n;
    // cout<<m<<" "<<n<<endl;
    // vector<vector<int>> mat(m, vector<int>(n));
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < n; j++) {
    //         cin>>mat[i][j];
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int n = 1000;
    cout<<n<<endl;
    for(int i=1;i<=n;i++) cout<<i<<endl;
}
