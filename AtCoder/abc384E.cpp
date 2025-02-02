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

vector<int> drow = {1,0,-1,0};
vector<int> dcol = {0,1,0,-1};


void checkMatrix(int &cnt,int row,int col,long long x,long long &st,vector<vector<long long>> &mat) {
	int n = mat.size() , m = mat[0].size();
	if(cnt == n * m) return;
	if(cnt)
	st += mat[row][col];
	mat[row][col] = 0;

	for(int i=0;i<4;i++) {
		int nr = row + drow[i];
		int nc = col + dcol[i];

		if(nr >= 0 && nc >= 0 && nr < n && nc < m && st > x * mat[nr][nc]) {

		}
	}
}

void solve() {
    int n,m;
    cin>>n>>m;
    long long x;
    cin>>x;
    int p,q;
    cin>>p>>q;
    p--;q--;

    vector<vector<long long>> mat(n,vector<long long>(m));
    for(int i=0;i<n;i++) {
    	for(int j=0;j<m;j++) {
    		cin>>mat[i][j];
    	}
    }
    long long st = 0;
    int cnt = 0;

    checkMatrix(cnt,p,q,x,st,mat);

    cout<<st<<endl;

}
