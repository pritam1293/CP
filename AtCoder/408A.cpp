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

void solve() {
    int n, s;
    cin>>n>>s;
    vector<double> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    double prev = 0;
    for(int i=0;i<n;i++) {
        double diff = a[i] - prev;
        if(diff >= s + 0.5) {
            cout<<"No"<<endl;
            return;
        }
        prev = a[i];
    }
    cout<<"Yes"<<endl;
}