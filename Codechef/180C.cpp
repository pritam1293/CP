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
    int n,k;
    cin>>n>>k;

    if(k < n/2 || k > n) {
        cout<<"-1"<<endl;
        return;
    }

    string s;
    bool flag = true;
    for(int i=0;i<n;i++) {
        if(flag) s += "A";
        else s += "B";
        flag = !flag;
    }

    int diff = n-k;
    int cnt = 0;
    string t = s;

    for(int i=0;i<n && cnt < diff;i += 2) {
        t[i] = 'C';
        cnt++;
    }
    cout<<s<<endl;
    cout<<t<<endl;
}