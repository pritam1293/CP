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
    double n;
    cin>>n;
    double low = 0, high = 1e5;
    for(int i=0;i<100;i++) {
        double mid = (low + high) / 2;

        double root = sqrt(mid);
        double curr = mid * mid + root;


        if(curr >= n) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    cout<<setprecision(8)<<low<<endl;
}