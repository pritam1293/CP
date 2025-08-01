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

void low(string &s) {
    for(int i=0;i<(int)s.size();i++) {
        if(s[i] >= 'a' && s[i] <= 'z') continue;
        else {
            s[i] += 32;
        }
    }
}

string generateTag(string caption) {
    string ans;
    string temp;
    for(auto& ch : caption) {
        if(ch != ' ') {
            temp += ch;
        }
        else {
            low(temp);
            temp[0] -= 32;
            ans += temp;
            temp.clear();
        }
    }
    if(!temp.empty()) {
        low(temp);
        temp[0] -= 32;
        ans += temp;
    }
    ans[0] += 32;
    ans = "#" + ans;
    // return
    while(ans.size() > 100) ans.pop_back();
    return ans;
}

void solve() {
    string s = "Leetcode daily streak achieved";
    cout<<generateTag(s)<<endl;
}