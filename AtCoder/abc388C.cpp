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

int search(int num,vector<int> &a , int end) {
    int st = 0;
    int idx = -1;
    while(st <= end) {
        int mid = (st+end)/2;
        if(a[mid] >= num) {
            idx = mid;
            end = mid-1;
        }
        else {
            st = mid+1;
        }
    }
    return idx;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    long long ans = 0;
    for(int i=0;i<n;i++) {
        int idx = search(2*a[i] , a,n-1);
        if(idx == -1) {
            break;
        }
        else {
            ans += (long long)(n-idx);
        }
    }
    cout<<ans<<endl;
}
