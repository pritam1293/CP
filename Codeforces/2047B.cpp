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
    cin>>n;
    string s;
    cin>>s;
    map<char,int> mp;
    for(int i=0;i<n;i++) {
    	mp[s[i]]++;
    }
    int freq = 0;
    char ch = s[0];
    int low = INT_MAX;
    char change = s[0];

    for(auto it : mp) {
    	if(it.second > freq) {
    		freq = it.second;
    		ch = it.first;
    	}
    	if(it.second < low) {
    		low = it.second;
    		change = it.first;
    	}
    }
    
    if(low  == freq) {
    	for(int i=0;i<n;i++) {
    		if(s[i] != ch) {
    			s[i] = ch;
    			break;
    		}
    	}
    }
	else {
	    for(int i=0;i<n;i++) {
	    	if(s[i] == change) {
	    		s[i] = ch;
	    		break;
	    	}
	    }
	}
    cout<<s<<endl;
}
