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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    map<int,int> mp;
    for(int i=0;i<n;i++) {
    	mp[a[i] % k]++;
    }

    int rem = -1;
    for(auto it : mp) {
    	if(it.second == 1) {
    		rem = it.first;
    		break;
    	}
    }

    if(rem == -1) {
    	cout<<"NO"<<endl;
    }
    else {
    	cout<<"YES"<<endl;
    	for(int i=0;i<n;i++) {
	    	if(a[i] % k == rem) {
	    		cout<<i+1<<endl;
	    		return;
	    	}
    	}
    }
}
