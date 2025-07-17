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
    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<vector<set<int>>> st(3, vector<set<int>>(3));
    for(int i=0;i<q;i++) {
        char x, y;
        cin>>x>>y;
        st[x-'a'][y-'a'].insert(i);
    }
    for(int i=0;i<n;i++) {
        if(s[i] == 'a') continue;
        if(s[i] == 'b') {
            if(!st[1][0].empty()) {
                st[1][0].erase(st[1][0].begin());
                s[i]--;
            }
            else if(!st[1][2].empty()) {
                int idx = *st[1][2].begin();
                auto lb = st[2][0].lower_bound(idx);
                if(lb != st[2][0].end()) {
                    st[1][2].erase(idx);
                    st[2][0].erase(lb);
                    s[i]--;
                }
            }
        }
        else {
            if(!st[2][0].empty()) {
                s[i] = 'a';
                st[2][0].erase(st[2][0].begin());
            }
            else if(!st[2][1].empty()) {
                int idx = *st[2][1].begin();
                st[2][1].erase(idx);
                s[i]--;
                auto lb = st[1][0].lower_bound(idx);
                if(lb != st[1][0].end()) {
                    st[1][0].erase(lb);
                    s[i]--;
                }
            }
        }
    }
    cout<<s<<endl;
}