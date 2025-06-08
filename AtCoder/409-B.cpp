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

int count(vector<int> &a, int val) {
    int cnt = 0;
    for(auto& it : a) {
        if(it >= val) cnt++;
    }
    return cnt;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int low = 0, high = 1e9;
    int ans = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(count(a, mid) >= mid) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    cout<<ans<<endl;
}