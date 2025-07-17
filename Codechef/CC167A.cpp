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
    int n;
    string s;
    cin>>n>>s;
    bool zero = false , one  = false;
    for(char c : s){
        if(c == '0') zero = true;
        else if(c == '1') one = true;
    }

    if(!zero || !one) {
        cout<<n<<endl;
    }
    else {
        cout<<1<<endl;
    }
}
