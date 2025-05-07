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

int search(vector<int> &a, int val) {
    int idx = a.size();
    int low = 0 , high = idx-1;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(a[mid] >= val) {
            idx = mid;
            high = mid-1;
        }
        else low = mid + 1;
    }
    return idx+1;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<k;i++) {
        int val;
        cin>>val;
        cout<<search(a, val)<<endl  ;
    }
}