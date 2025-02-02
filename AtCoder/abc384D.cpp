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

bool subarray(int n , vector<long long> &a , long long target) {
	set<long long> st;
	long long sum = 0;
	for(int i=0;i<n;i++) {
		sum += a[i];

		if(sum == target) return true;

		if(st.find(sum - target) != st.end()) return true;
		
		st.insert(sum);
	}
	return false;
}

void solve() {
    int n;
    cin>>n;
    long long target;
    cin>>target;
    long long sum = 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
    }
    
    long long k = (target + sum - 1ll) / sum;
    // cout<<k<<endl;

    if(k > 1) {
    	for(int i=0;i<n;i++) {
    		a.push_back(a[i]);
    	}
    	for(int i=0;i<n;i++) {
    		a.push_back(a[i]);
    	}
    	for(int i=0;i<n;i++) {
    		a.push_back(a[i]);
    	}
    	target -= (k - 2ll) * sum;
    }

    if(subarray(a.size() , a , target)) {
    	cout<<"Yes"<<endl;
    }
    else {
    	cout<<"No"<<endl;
    }
}
