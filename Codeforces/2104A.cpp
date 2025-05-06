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
    int a,b,c;
    cin>>a>>b>>c;
    int sum = a+b+c;
    if(sum % 3 != 0) {
        cout<<"NO"<<endl;
        return;
    } 
    int rem = c-b;
    int diff = b-a;
    if(diff > rem || (rem - diff) % 3 != 0) {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}