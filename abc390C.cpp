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

bool check(int row,int col,vector<string> &grid) {
    int top = row , bottom = -1 , left = col , right = -1;

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(grid[i][j] == '#') {
                top = min(top,i);
                bottom = max(bottom,i);
                left = min(left,j);
                right = max(right,j);
            }
        }
    }

    for(int i=top;i<=bottom;i++) {
        for(int j=left;j<=right;j++) {
            if(grid[i][j] == '.') return false;
        }
    }

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if((i < top || i > bottom || j < left || j > right) && grid[i][j] == '#'){
                return false;
            }
        }
    }
    return true;
}

void solve() {
    int h,w;
    cin>>h>>w;
    vector<string> grid(h);
    for(int i=0;i<h;i++) {
        cin>>grid[i];
    }

    if(check(h,w,grid)) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}
