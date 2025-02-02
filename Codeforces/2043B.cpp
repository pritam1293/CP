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
    int n,d;
    cin>>n>>d;
    cout<<"1 ";
    if(n >= 3 || d%3 ==0 ) {
        cout<<"3 ";
    }
    if(d == 5) {
        cout<<"5 ";
    }
    if(n >= 3 || d == 7) {
        cout<<"7 ";
    }
    if(n >= 6) {
        cout<<"9 ";
    }
    else {
        int fact = 1;
        int i = 2;
        while(i <= n) {
            fact *= i;
            i++;
        }
        if((fact * d) % 9 == 0) {
            cout<<"9 ";
        }
    }
    cout<<endl;
}
