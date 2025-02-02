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

int inf = 1e9;

void solve() {
    int h,w;
    cin>>h>>w;
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++) {
        cin>>s[i];
    }

    int si,sj,gi,gj;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if(s[i][j] == 'S') {
                si = i;
                sj = j;
            }
            else if(s[i][j] == 'G') {
                gi = i;
                gj = j;
            }
        }
    }

    int ans = inf;
    vector<vector<pair<int,int>>> dir(2);
    dir[0] = {{0,1} , {0,-1}};
    dir[1] = {{1,0} , {-1,0}};

    for(int i=0;i<2;i++) {
        vector<vector<int>> d(h,vector<int>(w , inf));
        d[si][sj] = 0;
        queue<pair<int,int>> q;
        q.push(si,sj);

        while(!q.empty()) {
            auto [i,j] = q.front();
            q.pop();
        }
    }
}
