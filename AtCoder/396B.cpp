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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    stack<int> st;
    for(int i=0;i<n;i++) {
        int op;
        cin>>op;
        if(op == 1) {
            int num;
            cin>>num;
            st.push(num);
        }
        else {
            if(st.empty()) {
                cout<<0<<endl;
            }
            else {
                cout<<st.top()<<endl;
                st.pop();
            }
        }
    }
}