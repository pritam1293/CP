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

void solve() {
    int h,w,d;
    cin>>h>>w>>d;
    vector<string> a(h);
    for(int i=0;i<h;i++) {
        cin>>a[i];
    }
    vector<pair<int,int>> cod , desk;
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if(a[i][j] == '.') {
                cod.push_back({i,j});
            }
            else {
                desk.push_back({i,j});
            }
        }
    }

    int n = cod.size() , m = desk.size();
    int ans = 0;

    for(int i=0;i<n;i++) {
        int x1 = cod[i].first , y1 = cod[i].second;

        for(int j=i+1;j<n;j++) {
            int x2 = cod[j].first , y2 = cod[j].second;
            int cnt = 0;

            for(int row=0;row<h;row++) {
                for(int col=0;col<w;col++) {
                    if(a[row][col] == '.') {
                        int d1 = abs(row - x1) + abs(col - y1);
                        int d2 = abs(row - x2) + abs(col - y2);

                        if(d1 <= d || d2 <= d) cnt++;
                    }
                }
            }
            ans = max(cnt , ans);
        }
    }
    cout<<ans<<endl;
}
