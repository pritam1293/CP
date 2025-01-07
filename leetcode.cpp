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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool substring(string &s , string &main) {
    int n = main.size() , m = s.size();
    for(int i=0;i<=n-m;i++) {
        if(main.substr(i,m) == s) return true;
    }
    return false;
}

vector<string> stringMatching(vector<string>& w) {
    int n = w.size();
    vector<string> ans;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i == j) continue;
            if(w[i].size() <= w[j].size() && substring(w[i] , w[j])) {
                ans.push_back(w[i]);
                break;
            }
        }
    }
    return ans;
}

void solve() {
    vector<string> w = {"leetcoder","leetcode","od","hamlet","am"};
    for(auto it : stringMatching(w)) {
        cout<<it<<endl;
    }
}
