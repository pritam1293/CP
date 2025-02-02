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
    int n,r;
    cin>>n>>r;
    for(int i=0;i<n;i++) {
    	int div,a;
    	cin>>div>>a;
    	if(div ==1 && r >= 1600 && r < 2800) {
    		r += a;
    	}
    	else if(div ==2 && r >= 1200 && r < 2400) {
    		r += a;
    	}
    }
    cout<<r;
}
