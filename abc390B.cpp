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

void solve() {
    int n;
    cin>>n;
    vector<double> arr(n);
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    double r = arr[1] / arr[0];

    for(int i=1;i<n;i++) {
        if(arr[i] != r * arr[i-1]) {
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}
