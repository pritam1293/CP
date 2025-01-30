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
    int n;
    cin>>n;
    map<int,int> freq;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        freq[a[i]]++;
    }
    int num = -1;
    for(auto it : freq) {
        if(it.second >= 4) {
            for(int i=0;i<4;i++) {
                cout<<it.first<<" ";
            }
            cout<<endl;
            return;
        }
        else if(it.second >= 2) {
            if(num == -1) {
                num = it.first;
            }
            else {
                cout<<num<<" "<<num<<" "<<it.first<<" "<<it.first<<endl;
                return;
            }
        }
    }
    if(num == -1) {
        cout<<"-1"<<endl;
        return;
    }
    vector<int> arr;
    int cnt = 0;
    for(int i=0;i<n;i++) {
        if(a[i] == num) cnt++;
        if(a[i] != num || cnt > 2) {
            arr.push_back(a[i]);
        }
    }

    sort(arr.begin(),arr.end());
    int size = arr.size();
    for(int i=1;i<size;i++) {
        int diff = arr[i] - arr[i-1];
        if(diff < 2*num) {
            cout<<num<<" ";
            cout<<num<<" ";
            cout<<arr[i-1]<<" ";
            cout<<arr[i]<<endl;
            return;
        }
    }
    cout<<"-1"<<endl;
}
