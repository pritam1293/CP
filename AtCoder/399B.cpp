#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> temp = a;
    sort(a.rbegin(),a.rend());
    map<int,int> mp;
    int i = 1;
    for(int val : a) {
        if(mp.find(val) == mp.end()) {
            mp[val] = i;
        }
        i++;
    }    
    for(int val : temp) {
        cout<<mp[val]<<endl;
    }
}