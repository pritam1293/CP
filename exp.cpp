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
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}


    bool canRemoved(string &s) {
        int n = s.size();
        if(n % 2 == 1) return false;
        stack<char> st;
        for(auto& ch : s) {
            if(!st.empty()) {
                char top = st.top();
                int diff = top - ch;
                if(diff == 1 || diff == -1 || diff == 25 || diff == -25) {
                    st.pop();
                }
                else {
                    st.push(ch);
                }
            }
            else {
                st.push(ch);
            }
        }
        return st.empty();
    }

void solve() {
    string s;
    cin>>s;
    string ans = s;
    int n = s.size();
    for(int i=0;i<n;i++) {
        string temp;
        for(int j=i;j<n;j++) {
            temp += s[j];
            if(canRemoved(temp)) {
                string t;
                for(int k=0;k<i;k++) {
                    t += s[k];
                }
                for(int k=j+1;k<n;k++) {
                    t += s[k];
                }
                cout<<t<<endl;
                ans = min(ans, t);
            }
        }
    }
    s = "bcda";
    cout<<canRemoved(s)<<endl;
    cout<<ans<<endl;
}
