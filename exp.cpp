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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    for(int j = 0; j < 8; j++) {
        int bit1 = (1 & (j >> 0));
        int bit2 = (1 & (j >> 1));
        int bit3 = (1 & (j >> 2));
        cout<<bit1<<bit2<<bit3<<endl;
    }

}
