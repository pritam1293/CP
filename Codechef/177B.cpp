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
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }

    int idx = -1;
    for(int i=0;i<n;i++) {
        if(a[i] == b[0]) {
            idx = i+1;
            break;
        }
    }

    int pivot = a[idx-1];
    vector<pair<int,int>> list(n);
    for(int i=0;i<n;i++) {
        list[i] = {abs(pivot - a[i]) , a[i]};
    }
    sort(list.begin(),list.end());
    for(int i=0;i<n;i++) {
        if(list[i].second != b[i]) {
            cout<<"-1"<<endl;
            return;
        }
    }
    cout<<idx<<endl;
}