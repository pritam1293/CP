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

vector<string> spiralorder(int row,int col,vector<string> &a) {
    vector<string> ans;
    int top = 0 , left = 0;
    int right = col-1 , bottom = row-1;
    int size = 0;
    while(size < row*col) {
        string s;
        for(int i=left;i<=right;i++) {
            s += a[top][i];
            size++;
            if(size == row*col){
                ans.push_back(s);
                return ans;
            }
        }
        top++;

        for(int i=top;i<=bottom;i++) {
            s += a[i][right];
            size++;
            if(size == row*col){
                ans.push_back(s);
                return ans;
            }
        }
        right--;

        for(int i=right;i>=left;i--) {
            s += a[bottom][i];
            size++;
            if(size == row*col){
                ans.push_back(s);
                return ans;
            }
        }
        bottom--;

        for(int i=bottom;i>=top;i--) {
            s += a[i][left];
            size++;
            if(size == row*col){
                ans.push_back(s);
                return ans;
            }
        }
        left++;
        ans.push_back(s);
    }
    return ans;
}

void solve() {
    int row,col;
    cin>>row>>col;
    vector<string> a(row);
    for(int i=0;i<row;i++) {
        cin>>a[i];
    }
    int cnt = 0;
    vector<string> spiral = spiralorder(row,col,a);
    for(auto arr : spiral) {
        int n = arr.size();
        for(int i=0;i<n;i++) {
            string temp;
            for(int j=0;j<4;j++) {
                temp += arr[(i+j)%n];
            }
            if(temp == "1543") cnt++;
        }
    }
    cout<<cnt<<endl;
}
