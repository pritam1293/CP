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
    int n;
    cin>>n;
    cout<<n<<endl;
    cout<<"HI"<<endl;
    map<int,int> mp;
    mp[1] = 2;
    mp[2] = 12;
    mp[4] = 20;
    mp[6] = 26;
    // for(auto& [f, s] : mp) {
    //     cout<<f<<s<<endl;
    // }
}
