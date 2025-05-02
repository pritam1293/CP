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
    int n,x;
    cin>>n>>x;
    if(x == 0) {
        if(n == 1) {
            cout<<"-1"<<endl;
        }
        else {
            cout<<(n % 2 == 0 ? n : n+3)<<endl;
        }
        return;
    }
    if(x == 1) {
        if(n % 2 == 0) {
            cout<< n-2 + 5 <<endl;
        }
        else {
            cout<<n<<endl;
        }
        return;
    }
    int one  = 0;
    int num = x;
    while(x > 0) {
        if(x % 2) one++;
        x /= 2;
    }
    int sum = 0;
    if(one >= n) {
        cout<<num<<endl;
    }
    else {
        if((n - one) % 2 == 0) {
            cout<< num + n-one <<endl;
        }
        else {
            cout<< num + n - one + 1 <<endl;
        }
    }
}
