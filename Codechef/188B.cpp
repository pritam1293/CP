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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool check(vector<int> &a, int mid) {
    for(auto& val : a) {
        
    }
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    int ans = n;
    int low = 0, high = n;
    while(low <= high) {
        int mid = (low + high)/2;
        if(check(a, mid)){
            high = mid-1;
            ans = mid;
        }
        else {
            low = mid+1;
        }
    }
    cout<<ans<<endl;
}