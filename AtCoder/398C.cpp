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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> freq;
    map<int,int> index;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        freq[a[i]]++;
        index[a[i]] = i+1;
    }
    int num = 0;
    int idx = -1;
    for(auto it : freq) {
        if(it.second == 1) {
            int val = it.first;
            if(val > num) {
                num = val;
                idx = index[val];
            }
        }
    }
    cout<<idx<<endl;
}