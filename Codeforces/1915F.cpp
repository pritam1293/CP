#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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

int first(vector<int> &c, int val) {
    int low = 0, high = c.size()-1, idx = 0;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(c[mid] >= val) {
            high = mid-1;
            idx = mid;
        }
        else {
            low = mid+1;
        }
    }
    return idx;
}

int last(vector<int> &c, int val) {
    int low = 0, high = c.size()-1;
    int idx = high;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(c[mid] <= val) {
            low = mid+1;
            idx = mid;
        }
        else high = mid-1;
    }
    return idx; 
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i]>>b[i];
    }
    vector<int> c = b;
    sort(c.begin(), c.end());
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += last(c, b[i]) - first(c, a[i]) + 1;
    }
    cout<<cnt<<endl;
}