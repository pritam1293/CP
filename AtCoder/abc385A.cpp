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
    int a,b,c;
    cin>>a>>b>>c;
    if(a == b && c == a) {
    	cout<<"Yes"<<endl;
    	return;
    }
    int sum = a+b+c;
    if(sum - max({a,b,c}) == max({a,b,c})) {
    	cout<<"Yes"<<endl;
    	return;
    }
    cout<<"No"<<endl;
}
