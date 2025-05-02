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

bool isSubstring(string s, set<string> &st) {
    if(st.find(s) != st.end()) return true;
    return false;
}


bool rec(int i, string s, set<string> &st, vector<int> &dp) {
    if(i == s.size()) return true;
    if(dp[i] != -1) return dp[i];

    bool flag = false;
    for(int j=i;j<s.size();j++) {
        if(st.find(s.substr(i, j-i+1)) != st.end() && rec(j+1, s, st, dp)) flag = true;
    }
    return dp[i] = flag;
}

// int Solution::wordBreak(string s, vector<string> &a) {
//         int n=s.length();
//         map<string,bool> m;
//         for(auto i : a)m[i]=true;
//         vector<bool> dp(n+1,0);
//         dp[0]=true;
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=19;j++){
//                 if(i+j-1<=n && m.find(s.substr(i-1,j))!=m.end())dp[i+j-1]=(dp[i-1] && true) || (dp[i+j-1]);
//             }
//         }
//         return dp[n];
// }


bool wordBreak(string &s, vector<string> &words) {
    set<string> st;
    for(string word : words) {
        st.insert(word);
    }
    int n = s.size();
    vector<int> dp(n+1, 0);
    dp[0] = true;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=19;j++) {
            if(i+j-1 <= n && st.find(s.substr(i-1, j)) != st.end()) {
                dp[i+j-1] = (dp[i-1] && true) || dp[i+j-1];
            }
        }
    }
    return dp[n];
}

void solve() {
    string s = "myinterviewtrainer";
    vector<string> words = {"trainer", "my", "interview"};
    cout<<(wordBreak(s, words) ? "Y" : "N")<<endl;

    s ="catsandog";
    words = {"cats","dog","sand","and","cat"};
    cout<<(wordBreak(s, words) ? "Y" : "N")<<endl;

    s ="applepenapple";
    words = {"apple","pen"};
    cout<<(wordBreak(s, words) ? "Y" : "N")<<endl;
}
