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
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int sum = a+b+c;

    int days = n / sum;
    days *= 3;
    n = n % sum;

    if(n <= 0) {
        cout<<days<<endl;
        return;
    }

    n -=a;
    days++;
    if(n <= 0) {
        cout<<days<<endl;
        return;
    }

    n -=b;
    days++;
    if(n <= 0) {
        cout<<days<<endl;
        return;
    }

    n -=c;
    days++;
    if(n <= 0) {
        cout<<days<<endl;
        return;
    }
}
