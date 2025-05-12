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

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    set<int> odd, even;
    for(int i=0;i<n;i++) {
        if(i % 2 == 0) even.insert(a[i]);
        else odd.insert(a[i]);
    }
    while(!odd.empty() && !even.empty()) {
        cout<< *even.begin() <<" ";
        cout<< *odd.begin() <<" ";
        even.erase(even.begin());
        odd.erase(odd.begin());
    }
    if(n % 2) {
        cout<< *even.begin() <<" ";
    }
    cout<<endl;
}