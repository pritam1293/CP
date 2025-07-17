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
    string a,b;
    cin>>n>>a>>b;
    int first = 0, second = 0;
    for(int i=0;i<n;i++) {
        if(i % 2 == 0 && a[i] == '1') first++; 
        else if(i % 2 == 1 && a[i] == '1') second++;
    }
    for(int i=0;i<n;i++) {
        if(i % 2 == 0 && b[i] == '1') second++; 
        else if(i % 2 == 1 && b[i] == '1') first++;
    }

    if(first <= (int)(n/2) && second <= (int)(n - (n/2))) {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}