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

/*
1 2 0
8 7 1
2 1 3
7 16 11
134 132 137
98 85 76
123 121 118
965321865 375544086 12551794
*/


void solve() {
    int l,r;
    cin>>l>>r;
    if(r > 1000000) {
        cout<<"skipped"<<endl;
        return;
    }
    int mx = -1;
    vector<int> ans(3);
    for(int a=l;a<=r-2;a++) {
        for(int b=a+1;b<=r-1;b++) {
            for(int c=b+1;c<=r;c++) {
                int curr = ((a^b) + (b^c) + (c^a));
                if(curr >= mx) {
                    ans[0] = a;
                    ans[1] = b;
                    ans[2] = c;
                    mx = curr;
                }
            }
        }
    }
    for(auto it :ans) {
        cout<<it<<" ";        
    }
    cout<<endl;
}
