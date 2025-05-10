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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    vector<int> arr;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            arr.push_back(a[i] + b[j]);
        }
    }
    sort(arr.begin(), arr.end());
    for(int i=0;i<arr.size();i++) {
        cout<< i+1 <<" "<<arr[i]<<endl;
    }
    for(int i=1;i<26;i++) {
        cout<<i<<" ";
    }
}
