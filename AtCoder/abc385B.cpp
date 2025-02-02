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

bool isValid(int row,int col,int n,int m,vector<string> &mat) {
	if(row >= 0 && col >= 0 && row < n && col < m && mat[row][col] != '#') return true;
	return false;
}

void solve() {
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    x--;y--;
    vector<string> mat(n);
    for(int i=0;i<n;i++) {
    	cin>>mat[i];
    }
    string s;
    cin>>s;

    set<pair<int,int>> st;


    int cnt = 0;
    for(char ch : s) {
    	if(ch == 'U') {
    		int nx = x - 1 , ny = y;
    		if(isValid(nx,ny,n,m,mat)) {
    			x = nx;
    			y = ny;
    			if(mat[x][y] == '@' && st.find({x,y}) == st.end()) {
    				cnt++;
    				st.insert({x,y});
    			}
    		}
    	}
    	else if(ch == 'D') {
    		int nx = x + 1 , ny = y;
    		if(isValid(nx,ny,n,m,mat)) {
    			x = nx;
    			y = ny;
    			if(mat[x][y] == '@' && st.find({x,y}) == st.end()) {
    				cnt++;
    				st.insert({x,y});
    			}
    		}
    	}
    	else if(ch == 'L') {
    		int nx = x , ny = y - 1;
    		if(isValid(nx,ny,n,m,mat)) {
    			x = nx;
    			y = ny;
    			if(mat[x][y] == '@' && st.find({x,y}) == st.end()) {
    				cnt++;
    				st.insert({x,y});
    			}
    		}
    	}
    	else {
    		int nx = x , ny = y + 1;
    		if(isValid(nx,ny,n,m,mat)) {
    			x = nx;
    			y = ny;
    			if(mat[x][y] == '@' && st.find({x,y}) == st.end()) {
    				cnt++;
    				st.insert({x,y});
    			}
    		}
    	}
    }
    cout<<x+1<<" "<<y+1<<" "<<cnt<<endl;
}
