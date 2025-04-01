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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int canJump(vector<int> &a) {
    int n = a.size();
    int last = n-1;
    for(int i=n-1;i>=0;i--) {
        if(i + a[i] >= last) last = i;
    }
    return last == 0;
}

void solve() {
    vector<int> a = {2,3,1,1,4};
    cout<<canJump(a)<<endl;
}