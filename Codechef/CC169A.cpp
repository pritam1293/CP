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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n,k;
    cin>>n,k;
    vector<int> freq(21); 
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        freq[a[i]]++;
    }
    // int tar = freq[k];
    int maxm = 0;
    for(int i=1;i<21;i++) {
        maxm = max(maxm , freq[i]);
    }
    if(maxm == freq[k]) {
        cout<<"0"<<endl;
        return;
    }
    //case -1
    vector<int> temp = freq;
    for(int i=0;i<n;i++) {
        if(a[i] == k) {
            break;
        }
        else {
            temp[a[i]]--;
        }
    }
    maxm = 0;
    for(int i=1;i<21;i++) {
        maxm = max(maxm , temp[i]);
    }
    if(maxm == freq[k]) {
        cout<<"1"<<endl;
        return;
    }

    temp = freq;
    for(int i=n-1;i>=0;i--) {
        if(a[i] == k) {
            break;
        }
        else {
            temp[a[i]]--;
        }
    }
    maxm = 0;
    for(int i=1;i<21;i++) {
        maxm = max(maxm , temp[i]);
    }
    if(maxm == freq[k]) {
        cout<<"1"<<endl;
        return;
    }
    cout<<2<<endl;
}
