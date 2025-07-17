#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int search(vector<int> &lis, int val) {
    int low = 0, high = lis.size();
    int idx = high;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(lis[mid] >= val) {
            idx = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
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
    vector<int> lis = {a[0]};
    for(int i=1;i<n;i++) {
        if(lis.back() < a[i]) lis.push_back(a[i]);
        else {
            int idx = search(lis, a[i]);
            lis[idx] = a[i];
        }
    }
    cout<<lis.size()<<endl;
}