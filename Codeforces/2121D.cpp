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

bool isSorted(vector<int> &arr, int n) {
    for(int i=1;i<n;i++) {
        if(arr[i-1] > arr[i]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    vector<int> opa, opb;
    while(!isSorted(a, n)) {
        for(int i=0;i<n-1;i++) {
            if(a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
                opa.push_back(i+1);
            }
        }
    }
    while(!isSorted(b, n)) {
        for(int i=0;i<n-1;i++) {
            if(b[i] > b[i+1]) {
                swap(b[i], b[i+1]);
                opb.push_back(i+1);
            }
        }
    }
    // for(auto it : a) {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // for(auto it : b) {
    //     cout<<it<<" ";
    // }
    // cout<<endl;
    // cout<< opa.size() + opb.size()<<endl;
    vector<int> swaps;
    for(int i=0;i<n;i++) {
        if(a[i] > b[i]) {
            swaps.push_back(i+1);
        }
    }
    int size = opa.size() + opb.size() + swaps.size();
    cout<<size<<endl;
    for(auto& i : opa) {
        cout<<"1 "<<i<<endl;
    }
    for(auto& i : opb) {
        cout<<"2 "<<i<<endl;
    }
    for(auto& i : swaps) {
        cout<<"3 "<<i<<endl;
    }
}