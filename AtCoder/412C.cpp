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

int search(vector<int> &a, int low, int val) {
    int high = a.size()-1;
    int idx = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(a[mid] <= val) {
            low = mid+1;
            idx = mid;
        }
        else  high = mid-1;
    }
    return idx;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a;
    int first, last;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        if(i == 0) first = x;
        else if(i == n-1) last = x;
        else if(x >= first) a.push_back(x);
    }
    sort(a.begin(), a.end());
    // for(auto it : a) {
    //     cout<<it<<" ";
    // }
    int curr = first;
    int idx = 0;
    int size = 2;
    while(2*curr < last) {
        int i = search(a, idx, 2*curr);
        if(i == -1) {
            cout<<"-1"<<endl;
            return;
        }
        else {
            size++;
            idx = i+1;
        }
        curr = a[i];
    }
    cout<<size<<endl;
}