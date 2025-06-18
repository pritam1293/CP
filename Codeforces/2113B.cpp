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
    int w, h, a, b;
    cin>>w>>h>>a>>b;
    int x1, y1, x2, y2;
    cin>>x1>>y1>>x2>>y2;

    int nx1 = (x1+a) % a;
    int nx2 = (x2+a) % a;
    int ny1 = (y1+b) % b;
    int ny2 = (y2+b) % b;

    if(nx1 == nx2 && (x1 != x2 || ny1 == ny2)) {//vertical
        cout<<"Yes"<<endl;
    }
    else if(ny1 == ny2 && y1 != y2) {//horizontal
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}