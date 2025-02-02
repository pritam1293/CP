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
    int n;
    cin>>n;
    vector<int> q(n) , r(n);
    for(int i=0;i<n;i++) {
    	cin>>q[i]>>r[i];
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++) {
    	int t,d;
    	cin>>t>>d;
    	t--;
    	int next;
    	int a = q[t];//q
    	int b = r[t];//r
    	if(d%a == b) {
    		next = d;
    	}
    	else {
    		int rem = d%a;
    		if(rem <= b) {
    			next = d + b - rem;
    		}
    		else {
    			next = d + a + b - rem;
    		}
    	}
    	cout<<next<<endl;
    }
}
