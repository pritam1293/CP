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
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int gcd = a[0];
    for(int i=1;i<n;i++) {
        gcd = __gcd(gcd, a[i]);
    }
    int cnt = 0;
    for(int i=0;i<n;i++) {
       if(gcd == a[i]) cnt++;
    }
    if(cnt) {
        cout<<(n-cnt)<<endl;
        return;
    }
    set<int> st;
    for(auto& val : a) {
        st.insert(val);
    }
    cout<<st.size()<<endl;
    return;
    int mx = *st.rbegin();
    vector<int> op(mx+1, -1);
    queue<int> q;
    for(auto& val : st) {
        op[val] = 0;
        q.push(val);
    }
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        if(top == gcd) break;
        for(auto& val : st) {
            int num = __gcd(top, val);
            if(op[num] == -1) {
                op[num] = 1 + op[top];
                q.push(num);
            }
        }
    }
    for(int i=1;i<=mx;i++) {
        cout<<op[i]<<" ";
    }
}