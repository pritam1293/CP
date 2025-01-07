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
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    int unique = mp.size();
    int freq = -1;
    int val;
    for(auto it : mp) {
        if(it.second > freq) {
            val = it.first;
            freq = it.second;
        }
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    int one = false;

    for(auto it : mp) {
        if(it.first == val && !one) {
            one = true;
            continue;
        } 
        pq.push(it.second);
    }

    while(k > 0 && !pq.empty()) {
        if( k >= pq.top()) {
            k -= pq.top();
            pq.pop();
            unique--;
        }
    }
    cout<<unique<<endl;
    // cout<<val<<endl;
}
