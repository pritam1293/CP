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

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));
    int val = n*n - 1;
    int top = 0, left = 0;
    int bottom = n-1, right = n-1;
    while(top <= bottom && left <= right) {
        for(int i=left;i<=right;i++) {
            a[top][i] = val;
            val--;
        }
        top++;

        for(int i=top;i<=bottom;i++) {
            a[i][right] = val;
            val--;
        }
        right--;

        if(top <= bottom) {
            for(int i=right;i>=left;i--) {
                a[bottom][i] = val;
                val--;
            }
            bottom--;
        }
        if(left <= right) {
            for(int i=bottom;i>=top;i--) {
                a[i][left] = val;
                val--;
            }
            left++;
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}