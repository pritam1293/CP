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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int h, w, n;
    cin>>h>>w>>n;
    map<int,int> row;
    map<int,int> col;
    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        row[x]++;
        col[x]++;
    }
    int query;
    cin>>query;
    while(query--) {
        int q, box;
        cin>>q>>box;
        if(q == 1) {
            cout<<row[box]<<endl;
            row[box] = 0;
        }
        else {
            cout<<col[box]<<endl;
            col[box] = 0;
        }
    }
}