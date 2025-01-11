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

void solve() {
    // int l = 0 , r = 1073741823;
    // int p2 = log2(r);
    // int num = pow(2,p2);
    // int a = 0;
    // int b = num-1;
    // int c = num;
    int a,b,c;
    cin>>a>>b>>c;
    cout<<((a^b) + (b^c) + (c^a))<<endl;
    
    // cout<<"0 "<<num-1<<" "<<num<<endl;
}
