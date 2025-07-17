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
    int rate, div;
    cin>>rate>>div;
    if(div == 1 && rate >= 1600 && rate <= 2999) {
        cout<<"Yes"<<endl;
    }
    else if(div == 2 && rate >= 1200 && rate <= 2399) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}